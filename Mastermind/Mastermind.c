#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>




void color_generator(char* str, int num_of_cells) {
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

//****************************************************************

void print_color(char* str, int num_of_cells) {
	for (int i = 0; i < num_of_cells; i++) {
		printf_s("%c", str[i]);
	}
    printf("\n");
}

void print_mastermind(int* str, int len,  int bulls) {
    printf_s("\nYour colors: ");
    print_color(str, len);
    printf_s("Bulls: %d\n\n", bulls);
}

//****************************************************************

/*
This function checks the number of bulls. Bulls are the numbers that stand on their city. In order to win you need to have 4 bulls.
Example:
Generated number 1234
Number entered: 1784
Bulls: 2
These are the numbers * 1 * and * 4 *

How this feature works:
the function equals the numbers by their index, if the numbers match, the counter is increased by 1.
*/
int how_many_bulls_mastermind(char* str, char* random_str, int num) {
    int counter = 0;
    for (int i = 0; i < num; i++) {
        if (str[i] == random_str[i]) {
            counter++;
        }
    }
    return counter;
}

/*
The function checks whether the numbers entered are the same. If the number differs, the function returns a value of 0, ie false.
*/
int colors_is_correct(char* str, char* random_str, int num) {
    for (int i = 0; i < num; i++) {
        if (str[i] != random_str[i]) {
            return 1;
        }
    }
    return 0;
}

//****************************************************************