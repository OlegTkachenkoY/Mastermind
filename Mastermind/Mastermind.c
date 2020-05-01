#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>



char color_generator(char* str, int num_of_cells) {
	srand(time(NULL));
	int rand_num;

	for (int i = 0; i < num_of_cells; i++) {
		rand_num = rand() % 6 + 1;

		if (rand_num == 1) str[i] = 'y';		//Y-yellow
		else if (rand_num == 2)	str[i] = 'g';	//G-green
		else if (rand_num == 3)	str[i] = 'r';	//R-red
		else if (rand_num == 4)	str[i] = 'p';	//P-pink
		else if (rand_num == 5)	str[i] = 'b';	//B-blue
		else str[i] = 'o';						//O-orange
	}
}

void print_color(char* str, int num_of_cells) {
	for (int i = 0; i < num_of_cells; i++) {
		printf_s("%c", str[i]);
	}
}