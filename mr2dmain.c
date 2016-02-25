#include <pic32mx.h>
#include <stdint.h>

extern const uint8_t const ground[512];
extern const uint8_t const hat[32];
extern const uint8_t const hat1[64];

int main(void) {

	hardware_init();
	display_init();
	int j_time = 0;
	int y = 2;
	int j_wait = 0;

	while(1) {
		if (j_time == 28){
			y = 2;
			j_time = 0;
		}
		add_img(0, 0, 512, ground);
		add_img(61, y, 8, eightbin_conv(8, hat1));
		delay(100000);
		if (j_wait == 0){
			if (getbtns() == 1) {

				y = 1;
				j_wait = 18;
			}
		}
		display_img();
		j_time++;
		if (j_wait > 0){
				j_wait--;
		}

	}
	return 0;
}
