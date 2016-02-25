#include <pic32mx.h>
#include <stdint.h>

int main(void) {

	hardware_init();
	display_init();
	start();
	start_select();
	run_game();

	return 0;
}
