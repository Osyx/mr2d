#include <pic32mx.h>
#include <stdint.h>

#define DISPLAY_VDD PORTFbits.RF6
#define DISPLAY_VBATT PORTFbits.RF5
#define DISPLAY_COMMAND_DATA PORTFbits.RF4
#define DISPLAY_RESET PORTGbits.RG9


#define DISPLAY_VDD_PORT PORTF
#define DISPLAY_VDD_MASK 0x40
#define DISPLAY_VBATT_PORT PORTF
#define DISPLAY_VBATT_MASK 0x20
#define DISPLAY_COMMAND_DATA_PORT PORTF
#define DISPLAY_COMMAND_DATA_MASK 0x10
#define DISPLAY_RESET_PORT PORTG
#define DISPLAY_RESET_MASK 0x200

extern char textbuffer[4][16];
extern char imgbuffer[4][128];

void hardware_init (){
  /* Set up peripheral bus clock */
	OSCCON &= ~0x180000;
	OSCCON |= 0x080000;

	/* Set up output pins */
	AD1PCFG = 0xFFFF;
	ODCE = 0x0;
	TRISECLR = 0xFF;
	PORTE = 0x0;

	/* Output pins for display signals */
	PORTF = 0xFFFF;
	PORTG = (1 << 9);
	ODCF = 0x0;
	ODCG = 0x0;
	TRISFCLR = 0x70;
	TRISGCLR = 0x200;

	/* Set up input pins */
	TRISDSET = (1 << 8);
	TRISFSET = (1 << 1);

	/* Set up SPI as master */
	SPI2CON = 0;
	SPI2BRG = 4;

	/* Clear SPIROV*/
	SPI2STATCLR &= ~0x40;
	/* Set CKP = 1, MSTEN = 1; */
        SPI2CON |= 0x60;

	/* Turn on SPI */
	SPI2CONSET = 0x8000;
}

void delay(int cyc) {
	int i;
	for(i = cyc; i > 0; i--);
}

int pow(x, a){
	int i;
	int pow_val = 1;
	for(i = 0; i < a; i++){
		pow_val *= x;
	}
	return pow_val;
}

uint8_t spi_send_recv(uint8_t data) {
	while(!(SPI2STAT & 0x08));
	SPI2BUF = data;
	while(!(SPI2STAT & 0x01));
	return SPI2BUF;
}

void display_init() {
	DISPLAY_COMMAND_DATA_PORT &= ~DISPLAY_COMMAND_DATA_MASK;
	delay(10);
	DISPLAY_VDD_PORT &= ~DISPLAY_VDD_MASK;
	delay(1000000);

	spi_send_recv(0xAE);
	DISPLAY_RESET_PORT &= ~DISPLAY_RESET_MASK;
	delay(10);
	DISPLAY_RESET_PORT |= DISPLAY_RESET_MASK;
	delay(10);

	spi_send_recv(0x8D);
	spi_send_recv(0x14);

	spi_send_recv(0xD9);
	spi_send_recv(0xF1);

	DISPLAY_VBATT_PORT &= ~DISPLAY_VBATT_MASK;
	delay(10000000);

	spi_send_recv(0xA1);
	spi_send_recv(0xC8);

	spi_send_recv(0xDA);
	spi_send_recv(0x20);

	spi_send_recv(0xAF);

	int i,j;
	for (i = 0; i < 32; i++) {
		for (j = 0; j < 128; j++) {
			imgbuffer[i][j] = 255;
		}
	}
}

void display_string(int line, char *s) {
	int i;
	if(line < 0 || line >= 4)
		return;
	if(!s)
		return;

	for(i = 0; i < 16; i++)
		if(*s) {
			textbuffer[line][i] = *s;
			s++;
		} else
			textbuffer[line][i] = ' ';
}

void add_img(int y, int x, int data_end, const uint8_t const *data) {
	int i, j;
	int z = 0;
	int k = 0;
	for (i = x; i < 4; i++){
		for(j = y; j < 128; j++){
			if (z >= data_end)
				break;
			imgbuffer[i][j] = data[z];
			z++;
		}
	}
}

void display_img() {
	int i, j;

	for(i = 0; i < 4; i++) {
		DISPLAY_COMMAND_DATA_PORT &= ~DISPLAY_COMMAND_DATA_MASK;
		spi_send_recv(0x22);
		spi_send_recv(i);

		spi_send_recv(0xf);
		spi_send_recv(0x10);

		DISPLAY_COMMAND_DATA_PORT |= DISPLAY_COMMAND_DATA_MASK;

		for(j = 0; j < 128; j++)
			spi_send_recv(~imgbuffer[i][j]);
	}
}

void display_image(int x, const uint8_t *data) {
	int i, j;

	for(i = 0; i < 4; i++) {
		DISPLAY_COMMAND_DATA_PORT &= ~DISPLAY_COMMAND_DATA_MASK;
		spi_send_recv(0x22);
		spi_send_recv(i);

		spi_send_recv(x & 0xF);
		spi_send_recv(0x10 | ((x >> 4) & 0xF));

		DISPLAY_COMMAND_DATA_PORT |= DISPLAY_COMMAND_DATA_MASK;

		for(j = 0; j < 128; j++)
			spi_send_recv(~data[i*128 + j]);
	}
}

void blackout (int x){
	int i, j;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 128; j++) {
			imgbuffer[i][j] = x;
		}
	}
}

const uint8_t const* eightbin_conv (int bredd, const uint8_t const *data) {
	 uint8_t new_data[bredd * 4];
	 int i;
	 for (i = 0; i < bredd * 4; i++){
		 new_data[i] = 0;
	 }
	 int bin, eightbit;
	 int onebit = 0;
	 int onebit_spot = 0;
	 for (eightbit = 0; eightbit < bredd * 4; eightbit++){
			for (bin = 0; bin < bredd; bin++){
				new_data[eightbit] += data[onebit] * pow(2, bin);
				onebit += bredd;
			}
			onebit_spot += 1;
			if (onebit_spot == bredd)
				onebit_spot = bredd * 8;
			if (onebit_spot == (bredd * 8) + bredd)
				onebit_spot = bredd * 8 * 2;
			if (onebit_spot == (bredd * 8 * 2) + bredd)
				onebit_spot = bredd * 8 * 3;
			onebit = onebit_spot;
	 }
	 return new_data;
}

int getbtns (void) {
  int retur = (PORTD & 0x00e0) >> 5;
  return retur;
}
