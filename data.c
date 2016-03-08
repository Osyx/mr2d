#include <stdint.h>

char textbuffer[4][16];
char imgbuffer[32][128];

const uint8_t const font[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 94, 0, 0, 0, 0,
	0, 0, 4, 3, 4, 3, 0, 0,
	0, 36, 126, 36, 36, 126, 36, 0,
	0, 36, 74, 255, 82, 36, 0, 0,
	0, 70, 38, 16, 8, 100, 98, 0,
	0, 52, 74, 74, 52, 32, 80, 0,
	0, 0, 0, 4, 3, 0, 0, 0,
	0, 0, 0, 126, 129, 0, 0, 0,
	0, 0, 0, 129, 126, 0, 0, 0,
	0, 42, 28, 62, 28, 42, 0, 0,
	0, 8, 8, 62, 8, 8, 0, 0,
	0, 0, 0, 128, 96, 0, 0, 0,
	0, 8, 8, 8, 8, 8, 0, 0,
	0, 0, 0, 0, 96, 0, 0, 0,
	0, 64, 32, 16, 8, 4, 2, 0,
	0, 62, 65, 73, 65, 62, 0, 0,
	0, 0, 66, 127, 64, 0, 0, 0,
	0, 0, 98, 81, 73, 70, 0, 0,
	0, 0, 34, 73, 73, 54, 0, 0,
	0, 0, 14, 8, 127, 8, 0, 0,
	0, 0, 35, 69, 69, 57, 0, 0,
	0, 0, 62, 73, 73, 50, 0, 0,
	0, 0, 1, 97, 25, 7, 0, 0,
	0, 0, 54, 73, 73, 54, 0, 0,
	0, 0, 6, 9, 9, 126, 0, 0,
	0, 0, 0, 102, 0, 0, 0, 0,
	0, 0, 128, 102, 0, 0, 0, 0,
	0, 0, 8, 20, 34, 65, 0, 0,
	0, 0, 20, 20, 20, 20, 0, 0,
	0, 0, 65, 34, 20, 8, 0, 0,
	0, 2, 1, 81, 9, 6, 0, 0,
	0, 28, 34, 89, 89, 82, 12, 0,
	0, 0, 126, 9, 9, 126, 0, 0,
	0, 0, 127, 73, 73, 54, 0, 0,
	0, 0, 62, 65, 65, 34, 0, 0,
	0, 0, 127, 65, 65, 62, 0, 0,
	0, 0, 127, 73, 73, 65, 0, 0,
	0, 0, 127, 9, 9, 1, 0, 0,
	0, 0, 62, 65, 81, 50, 0, 0,
	0, 0, 127, 8, 8, 127, 0, 0,
	0, 0, 65, 127, 65, 0, 0, 0,
	0, 0, 32, 64, 64, 63, 0, 0,
	0, 0, 127, 8, 20, 99, 0, 0,
	0, 0, 127, 64, 64, 64, 0, 0,
	0, 127, 2, 4, 2, 127, 0, 0,
	0, 127, 6, 8, 48, 127, 0, 0,
	0, 0, 62, 65, 65, 62, 0, 0,
	0, 0, 127, 9, 9, 6, 0, 0,
	0, 0, 62, 65, 97, 126, 64, 0,
	0, 0, 127, 9, 9, 118, 0, 0,
	0, 0, 38, 73, 73, 50, 0, 0,
	0, 1, 1, 127, 1, 1, 0, 0,
	0, 0, 63, 64, 64, 63, 0, 0,
	0, 31, 32, 64, 32, 31, 0, 0,
	0, 63, 64, 48, 64, 63, 0, 0,
	0, 0, 119, 8, 8, 119, 0, 0,
	0, 3, 4, 120, 4, 3, 0, 0,
	0, 0, 113, 73, 73, 71, 0, 0,
	0, 0, 127, 65, 65, 0, 0, 0,
	0, 2, 4, 8, 16, 32, 64, 0,
	0, 0, 0, 65, 65, 127, 0, 0,
	0, 4, 2, 1, 2, 4, 0, 0,
	0, 64, 64, 64, 64, 64, 64, 0,
	0, 0, 1, 2, 4, 0, 0, 0,
	0, 0, 48, 72, 40, 120, 0, 0,
	0, 0, 127, 72, 72, 48, 0, 0,
	0, 0, 48, 72, 72, 0, 0, 0,
	0, 0, 48, 72, 72, 127, 0, 0,
	0, 0, 48, 88, 88, 16, 0, 0,
	0, 0, 126, 9, 1, 2, 0, 0,
	0, 0, 80, 152, 152, 112, 0, 0,
	0, 0, 127, 8, 8, 112, 0, 0,
	0, 0, 0, 122, 0, 0, 0, 0,
	0, 0, 64, 128, 128, 122, 0, 0,
	0, 0, 127, 16, 40, 72, 0, 0,
	0, 0, 0, 127, 0, 0, 0, 0,
	0, 120, 8, 16, 8, 112, 0, 0,
	0, 0, 120, 8, 8, 112, 0, 0,
	0, 0, 48, 72, 72, 48, 0, 0,
	0, 0, 248, 40, 40, 16, 0, 0,
	0, 0, 16, 40, 40, 248, 0, 0,
	0, 0, 112, 8, 8, 16, 0, 0,
	0, 0, 72, 84, 84, 36, 0, 0,
	0, 0, 8, 60, 72, 32, 0, 0,
	0, 0, 56, 64, 32, 120, 0, 0,
	0, 0, 56, 64, 56, 0, 0, 0,
	0, 56, 64, 32, 64, 56, 0, 0,
	0, 0, 72, 48, 48, 72, 0, 0,
	0, 0, 24, 160, 160, 120, 0, 0,
	0, 0, 100, 84, 84, 76, 0, 0,
	0, 0, 8, 28, 34, 65, 0, 0,
	0, 0, 0, 126, 0, 0, 0, 0,
	0, 0, 65, 34, 28, 8, 0, 0,
	0, 0, 4, 2, 4, 2, 0, 0,
	0, 120, 68, 66, 68, 120, 0, 0,
};

const uint8_t const ground[] = {
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1,
};

const uint8_t const start_screen[] = {
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 63, 63, 63, 7, 7,
	7, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	3, 3, 3, 227, 3, 7, 255, 255, 255, 7, 3, 227, 3, 3, 3, 255, 255,
	63, 63, 63, 127, 63, 63, 63, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 207, 199, 199, 227, 243, 243, 227, 3, 7, 15, 255, 255, 255, 3,
	3, 3, 227, 227, 227, 227, 195, 135, 7, 15, 63, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 7, 7, 7, 63, 63, 63, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 129, 129, 129, 0, 0, 0, 112, 112, 112, 143, 143, 143, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 255, 255, 224, 0, 7,
	0, 224, 255, 255, 0, 0, 0, 255, 255, 0, 0, 0, 254, 255, 255, 255, 255,
	63, 63, 63, 255, 255, 255, 255, 255, 255, 255, 255, 255, 127, 63, 15, 7, 67,
	97, 112, 120, 124, 127, 255, 255, 255, 0, 0, 0, 63, 63, 63, 63, 63, 15,
	0, 128, 224, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 143, 143, 143,
	112, 112, 112, 0, 0, 0, 129, 129, 129, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 227, 227, 227, 0, 0, 0, 0,
	0, 0, 227, 227, 227, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 254, 254, 254, 255, 255, 243, 122, 2, 122, 243, 127, 1, 238, 238, 14, 127,
	159, 14, 78, 78, 79, 255, 255, 255, 255, 254, 254, 254, 255, 159, 111, 111, 15,
	255, 255, 31, 79, 78, 14, 126, 254, 14, 206, 30, 206, 14, 254, 15, 79, 79,
	78, 254, 254, 254, 254, 254, 254, 254, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 227, 227, 227, 0, 0, 0, 0, 0, 0, 227, 227,
	227, 255, 255, 255, 255, 255, 255, 255, 255, 255, 7, 7, 7, 7, 7, 7, 7,
	7, 7, 0, 0, 0, 7, 7, 7, 7, 7, 7, 0, 0, 0, 7, 7, 7,
	7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
	7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
	7, 7, 7, 7, 7, 7, 5, 5, 4, 7, 7, 7, 7, 7, 7, 7, 7,
	7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
	7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 0,
	0, 7, 7, 7, 7, 7, 7, 0, 0, 0, 7, 7, 7, 7, 7, 7, 7,
	7, 7,
};

const uint8_t const Start_settings[] = {
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 227, 193, 132, 142, 30, 29, 57, 112, 255, 247, 3, 1, 0, 247, 255,
	207, 199, 247, 119, 119, 7, 15, 63, 255, 247, 7, 7, 15, 239, 231, 231, 255,
	247, 3, 1, 0, 247, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 227, 193, 132, 142, 30, 29, 57, 112, 255, 31, 15, 39, 183, 183, 143,
	159, 255, 247, 3, 1, 0, 247, 255, 247, 3, 1, 0, 247, 255, 247, 4, 0,
	5, 255, 247, 7, 7, 7, 255, 247, 7, 7, 63, 255, 255, 15, 15, 7, 247,
	15, 15, 239, 255, 255, 143, 7, 55, 39, 71, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 240, 249, 243, 247, 247, 243,
	248, 252, 255, 255, 248, 240, 240, 255, 255, 249, 240, 240, 247, 251, 240, 240, 240,
	255, 247, 240, 240, 240, 247, 255, 255, 255, 255, 248, 240, 240, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 240, 249, 243, 247, 247, 243,
	248, 252, 255, 252, 248, 240, 243, 247, 251, 255, 255, 255, 248, 240, 240, 255, 255,
	255, 248, 240, 240, 255, 255, 119, 48, 16, 48, 119, 247, 240, 240, 240, 247, 247,
	240, 240, 240, 247, 255, 147, 1, 102, 102, 102, 103, 143, 255, 255, 241, 251, 247,
	246, 240, 252, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 31, 31, 3, 3, 0, 0,
	0, 0, 0, 3, 3, 31, 31, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255,
};

const uint8_t const Start_start[] = {
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 227, 193, 132, 142, 30, 29, 57, 112, 255, 247, 3, 1, 0, 247, 255,
	207, 199, 247, 119, 119, 7, 15, 63, 255, 247, 7, 7, 15, 239, 231, 231, 255,
	247, 3, 1, 0, 247, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 227, 193, 132, 142, 30, 29, 57, 112, 255, 31, 15, 39, 183, 183, 143,
	159, 255, 247, 3, 1, 0, 247, 255, 247, 3, 1, 0, 247, 255, 247, 4, 0,
	5, 255, 247, 7, 7, 7, 255, 247, 7, 7, 63, 255, 255, 15, 15, 7, 247,
	15, 15, 239, 255, 255, 143, 7, 55, 39, 71, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 240, 249, 243, 247, 247, 243,
	248, 252, 255, 255, 248, 240, 240, 255, 255, 121, 48, 16, 55, 123, 240, 240, 240,
	255, 247, 240, 240, 240, 247, 255, 255, 255, 255, 248, 240, 240, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 240, 249, 243, 247, 247, 243,
	248, 252, 255, 252, 248, 240, 243, 247, 251, 255, 255, 255, 248, 240, 240, 255, 255,
	255, 248, 240, 240, 255, 255, 247, 240, 240, 240, 247, 247, 240, 240, 240, 247, 247,
	240, 240, 240, 247, 255, 147, 1, 102, 102, 102, 103, 143, 255, 255, 241, 251, 247,
	246, 240, 252, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 31, 31, 3,
	3, 0, 0, 0, 0, 0, 3, 3, 31, 31, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255,
};

const uint8_t const settings_normal[] = {
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 15, 239, 239, 239, 207, 31, 255, 255, 47, 191, 31, 143,
	175, 63, 15, 175, 255, 15, 255, 255, 63, 191, 191, 127, 255, 127, 63, 255, 255, 63,
	255, 255, 15, 191, 31, 191, 191, 63, 127, 255, 255, 63, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 240, 247, 247, 247, 243, 248, 255, 255, 240, 255,
	240, 255, 255, 253, 248, 255, 255, 240, 255, 252, 248, 247, 247, 251, 255, 252, 240, 247,
	247, 240, 255, 255, 240, 255, 248, 247, 247, 223, 220, 225, 248, 254, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	7, 207, 31, 127, 255, 7, 255, 127, 63, 223, 223, 31, 127, 255, 31, 159, 223, 223,
	31, 223, 223, 63, 223, 223, 31, 255, 255, 159, 95, 95, 63, 255, 255, 7, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 7, 247, 247,
	247, 239, 15, 255, 255, 31, 95, 95, 31, 255, 255, 31, 159, 223, 223, 7, 127, 191,
	223, 255, 255, 255, 255, 143, 183, 183, 39, 111, 255, 127, 63, 223, 223, 63, 127, 255,
	31, 255, 255, 31, 255, 255, 7, 191, 31, 95, 223, 191, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 248, 255, 255, 254, 248, 248, 255, 254, 252, 251, 123, 56, 30, 15, 24, 63,
	127, 255, 248, 255, 255, 248, 255, 255, 248, 255, 252, 248, 251, 249, 248, 255, 255, 248,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 248,
	251, 251, 251, 253, 252, 255, 252, 248, 251, 249, 248, 255, 255, 248, 255, 255, 255, 248,
	254, 252, 249, 255, 255, 255, 255, 253, 251, 251, 251, 252, 255, 254, 252, 251, 251, 252,
	254, 254, 248, 251, 251, 248, 255, 255, 248, 253, 249, 251, 250, 252, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255,
};

const uint8_t const settings_ds[] = {
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 15, 239, 239, 239, 207, 31, 255, 255, 47, 191, 31, 143,
	175, 63, 15, 175, 255, 15, 255, 255, 63, 191, 191, 127, 255, 127, 63, 255, 255, 63,
	255, 255, 15, 191, 31, 191, 191, 63, 127, 255, 255, 63, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 240, 247, 247, 247, 243, 248, 255, 255, 240, 255,
	240, 255, 255, 253, 248, 255, 255, 240, 255, 252, 248, 247, 247, 251, 255, 252, 240, 247,
	247, 240, 255, 255, 240, 255, 248, 247, 247, 223, 220, 225, 248, 254, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	7, 207, 31, 127, 255, 7, 255, 127, 63, 223, 223, 31, 127, 255, 31, 159, 223, 223,
	31, 223, 223, 63, 223, 223, 31, 255, 255, 159, 95, 95, 63, 255, 255, 7, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 7, 247, 247,
	247, 239, 15, 255, 255, 31, 95, 95, 31, 255, 255, 31, 159, 223, 223, 7, 127, 191,
	223, 255, 255, 255, 255, 143, 183, 183, 39, 111, 255, 127, 63, 223, 223, 63, 127, 255,
	31, 255, 255, 31, 255, 255, 7, 191, 31, 95, 223, 191, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 248, 255, 255, 254, 248, 248, 255, 254, 252, 251, 251, 252, 254, 255, 248, 255,
	255, 255, 248, 255, 255, 248, 255, 255, 248, 255, 252, 248, 251, 249, 248, 255, 255, 248,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 248,
	251, 251, 251, 253, 252, 255, 252, 248, 251, 249, 248, 255, 255, 248, 255, 255, 255, 248,
	254, 252, 121, 63, 31, 15, 31, 57, 123, 251, 251, 252, 255, 254, 252, 251, 251, 252,
	254, 254, 248, 251, 251, 248, 255, 255, 248, 253, 249, 251, 250, 252, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255,
};

const uint8_t const ep2[] = {
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 127, 127, 127, 127, 127, 127, 255, 127, 127, 127, 127, 127, 255, 255, 127,
	127, 255, 127, 127, 63, 63, 127, 255, 255, 255, 127, 127, 127, 127, 255, 255, 255,
	255, 127, 127, 127, 127, 127, 255, 255, 255, 127, 127, 127, 127, 127, 127, 255, 255,
	255, 255, 127, 127, 255, 127, 127, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 128, 128, 146, 146, 146, 158,
	255, 128, 128, 230, 230, 240, 240, 255, 128, 128, 239, 200, 152, 155, 147, 130, 198,
	243, 192, 140, 158, 158, 158, 192, 225, 255, 255, 128, 128, 158, 158, 158, 192, 225,
	255, 128, 128, 146, 146, 146, 158, 255, 255, 255, 255, 128, 128, 255, 128, 128, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 247, 247, 7, 247, 7, 223, 223,
	7, 255, 7, 87, 87, 87, 255, 255, 7, 215, 215, 39, 7, 87, 87, 87, 247,
	247, 7, 247, 135, 127, 127, 7, 255, 7, 215, 215, 39, 7, 231, 159, 7, 255,
	255, 255, 143, 119, 119, 103, 159, 7, 215, 215, 215, 255, 255, 7, 199, 63, 159,
	7, 255, 7, 215, 215, 39, 255, 255, 47, 55, 87, 111, 7, 119, 119, 7, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255,
};

const uint8_t const story[] = {
	255, 255, 255, 255, 255, 255, 255, 255, 255, 247, 203, 189, 126, 142, 254, 226, 254,
	226, 230, 238, 230, 230, 246, 230, 246, 254, 230, 246, 230, 230, 230, 230, 246, 230,
	246, 254, 230, 230, 230, 254, 246, 254, 230, 246, 230, 246, 230, 246, 98, 190, 221,
	235, 247, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 248, 224, 128, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	239, 215, 187, 124, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254,
	254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254,
	254, 254, 254, 254, 254, 255, 63, 191, 135, 23, 16, 130, 130, 16, 23, 135, 191, 63,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 252, 248, 240, 224, 192, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128,
	192, 255, 255, 255, 255, 255, 255, 255, 79, 7, 35, 95, 254, 255, 255, 255, 255, 255,
	255, 175, 23, 55, 71, 223, 191, 127, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 127, 127, 15, 47, 33, 5, 4, 32, 160, 132, 244,
	240, 240, 244, 132, 160, 32, 4, 5, 33, 47, 15, 127, 127, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 254, 252, 252, 248, 248, 240, 240, 240, 224, 224, 224, 224, 224, 224, 192, 192,
	192, 192, 192, 224, 224, 224, 224, 224, 224, 240, 240, 240, 248, 248, 252, 252, 254,
	255, 255, 255, 255, 3, 3, 3, 3, 3, 3, 3, 1, 2, 2, 1, 3, 3, 3, 3, 3, 3, 3, 1, 2, 2, 1,
	3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 1, 1, 0, 0, 1, 1, 0,
	3, 3, 3, 3, 3, 3, 3, 3, 0, 1, 1, 0, 0, 1, 1, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
	3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
	3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
};

const uint8_t const died[] = {
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 63, 127, 255, 255, 255, 255, 255, 255, 255, 63, 63, 255, 255,
	255, 127, 127, 63, 63, 63, 63, 63, 127, 255, 255, 255, 255, 63, 63, 255, 255, 255,
	255, 255, 255, 255, 255, 63, 63, 255, 255, 255, 255, 255, 255, 255, 255, 127, 63, 63,
	63, 63, 63, 63, 63, 127, 127, 255, 255, 255, 255, 63, 63, 255, 255, 255, 127, 63,
	63, 63, 63, 63, 63, 63, 63, 63, 255, 255, 127, 63, 63, 63, 63, 63, 63, 63,
	127, 127, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 254, 252, 248, 227, 7, 15, 199, 225, 248, 252, 255,
	255, 3, 0, 252, 254, 255, 255, 255, 255, 255, 254, 48, 1, 135, 255, 0, 0, 255,
	255, 255, 255, 255, 255, 255, 255, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 0,
	0, 255, 255, 255, 255, 255, 255, 254, 252, 0, 3, 255, 255, 0, 0, 255, 255, 255,
	0, 0, 207, 207, 207, 207, 207, 207, 207, 255, 255, 255, 0, 0, 255, 255, 255, 255,
	255, 255, 254, 252, 0, 3, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 240, 240, 255, 255, 255,
	255, 255, 255, 255, 252, 248, 249, 243, 243, 243, 243, 243, 249, 252, 254, 255, 255, 255,
	252, 248, 243, 243, 243, 243, 243, 243, 248, 252, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 248, 240, 243, 243, 243, 243, 243, 243, 249, 248, 252, 255, 255, 255, 240, 240, 255,
	255, 255, 248, 240, 243, 243, 243, 243, 243, 243, 243, 243, 255, 255, 248, 240, 243, 243,
	243, 243, 243, 243, 249, 248, 252, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255,
};

const uint8_t const victory[] = {
	255, 223, 31, 255, 255, 255, 255, 127, 31, 255, 255, 31, 255, 255, 127, 63, 159, 223,
	223, 159, 63, 255, 223, 223, 223, 31, 31, 223, 223, 223, 127, 63, 159, 223, 223, 159,
	63, 127, 255, 255, 31, 223, 223, 223, 223, 31, 63, 255, 223, 31, 127, 255, 255, 255,
	63, 159, 255, 255, 255, 255, 255, 255, 255, 255, 63, 159, 63, 255, 255, 255, 255, 127,
	63, 159, 223, 223, 159, 63, 255, 255, 31, 255, 255, 255, 255, 255, 31, 31, 255, 255,
	31, 255, 255, 31, 223, 223, 223, 223, 223, 255, 223, 31, 255, 255, 255, 255, 127, 31,
	255, 255, 31, 223, 223, 223, 223, 223, 255, 255, 31, 223, 223, 223, 223, 159, 63, 255,
	255, 255, 255, 255, 254, 240, 135, 159, 195, 248, 255, 255, 255, 128, 255, 255, 224, 207,
	159, 191, 191, 159, 207, 255, 255, 255, 255, 128, 128, 255, 255, 255, 224, 207, 159, 191,
	191, 159, 207, 224, 255, 255, 128, 253, 253, 253, 249, 224, 142, 255, 255, 255, 254, 248,
	129, 252, 254, 255, 255, 255, 255, 255, 255, 191, 135, 240, 246, 247, 246, 240, 135, 159,
	255, 224, 207, 159, 191, 191, 159, 207, 255, 255, 128, 253, 253, 253, 253, 253, 128, 128,
	255, 255, 128, 255, 255, 128, 189, 189, 189, 189, 189, 255, 255, 254, 240, 135, 159, 195,
	248, 255, 255, 255, 128, 189, 189, 189, 189, 189, 255, 255, 128, 191, 191, 191, 159, 223,
	192, 240, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255,
};

const uint8_t const hole[] = {
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
};

const uint8_t const hat[] = {
	1, 1, 0, 1,
	1, 0, 0, 1,
	0, 0, 0, 1,
	0, 0, 1, 0,
	1, 0, 0, 1,
	0, 0, 0, 0,
	1, 0, 0, 1,
	0, 1, 1, 0,
};

const uint8_t const jump[] = {
	1, 1, 0, 1, 1, 1, 1, 1,
	1, 0, 0, 1, 1, 1, 1, 1,
	0, 0, 0, 1, 1, 1, 1, 1,
	0, 0, 1, 0, 1, 1, 1, 1,
	1, 0, 0, 1, 1, 1, 1, 1,
	0, 0, 0, 0, 1, 1, 1, 1,
	1, 0, 0, 1, 1, 1, 1, 1,
	0, 0, 0, 0, 1, 1, 1, 1,
};

const uint8_t const flow[] = {
	1, 1, 1, 1,
	1, 0, 1, 1,
	0, 0, 0, 1,
	1, 0, 1, 1,
	1, 1, 0, 1,
	0, 1, 0, 0,
	1, 0, 0, 1,
	1, 1, 0, 1,
};

const uint8_t const flower[] = {
	219, 177, 11, 223,
};

const uint8_t const hat1[] = {
	1, 1, 0, 1, 1, 1, 1, 1,
	1, 0, 0, 1, 1, 1, 1, 1,
	0, 0, 0, 1, 1, 1, 1, 1,
	0, 0, 1, 0, 1, 1, 1, 1,
	1, 0, 0, 1, 1, 1, 1, 1,
	0, 0, 0, 0, 1, 1, 1, 1,
	1, 0, 0, 1, 1, 1, 1, 1,
	0, 1, 1, 0, 1, 1, 1, 1,
};
