#include <pic32mx.h>
#include <stdint.h>

int main(void) {

	hardware_init();
	display_init();
	start();
	start_select();
	opening();
	run_game();
	you_died();
	main();

	return 0;
}
