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
extern const uint8_t const Start_start[512];
extern const uint8_t const start_screen[512];
extern const uint8_t const Start_settings[512];
extern const uint8_t const ground[512];
extern const uint8_t const ep2[512];
extern const uint8_t const hat[32];
extern const uint8_t const hole[16];
extern const uint8_t const hat1[64];

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

void start(){
  add_img(0,0,512, start_screen);
  while(1){
    display_img();
    if (getbtns() == 1)
      break;
  }
  delay(10000);
}

void start_select() {
  delay(100000);
  int wait = 0;
  int previous = 0;
  while(1){
    if (wait < 1) {
      if (getbtns() == 1) {
        if (previous == 0) {
          add_img(0, 0, 512, Start_start);
          previous = 1;
        }
        else {
          add_img(0, 0, 512, Start_settings);
          previous = 0;
        }
        wait = 700;
      }
      if (getbtns() == 2) {
        if (previous == 0) {
          add_img(0, 0, 512, Start_start);
          previous = 1;
        }
        else {
          add_img(0, 0, 512, Start_settings);
          previous = 0;
        }
        wait = 700;
      }
      if (getbtns() == 4)
          break;
      display_img();
    }
    if (wait > 0)
      wait--;
    delay(10000);
  }
}

void story(){
  add_img(0,0,512, ep2);
  while(1){
    display_img();
    if (getbtns() == 1)
      break;
  }
  delay(1000000);
}

void run_game() {
  int j_time = 0;
	int y = 2;
	int j_wait = 0;
	double hole_x = 128;
	while(1) {
		if (y == 0){
			//break;
		}
		if (j_time == 28){
			y = 2;
			j_time = 0;
		}
		if(y == 2 && (hole_x < 61) && (hole_x > 53)) {
				y = 3;
		}
		add_img(0, 0, 512, ground);
		add_img(hole_x, 3, 16, hole);
		add_img(61, y, 8, eightbin_conv(8, hat1));
		delay(100000);
		if (j_wait == 0){
			if (getbtns() == 1) {
					y = 1;
					j_wait = 18;
			}
		}
		if (getbtns() == 2) {
				add_img(80, 3, 16, hole);
		}
		display_img();
		j_time++;
		if (j_wait > 0){
				j_wait--;
		}
		hole_x -= 0.5;
		if (hole_x < -16)
			hole_x = 128;
	}
}
