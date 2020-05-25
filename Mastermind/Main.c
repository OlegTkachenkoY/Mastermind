#include "Mastermind.h"
#include "Errors.h"

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>


int main() {
	int num_of_cells;
	int counter = 1;
	char* random_str, * str;

	num_of_cells = mastermind_num_check();


	random_str = (char*)malloc(num_of_cells * sizeof(int));
	str = (char*)malloc(num_of_cells * sizeof(int));

	color_generator(random_str, num_of_cells);
	//print_color(random_str, num_of_cells);


	mastermind_color_check(str, num_of_cells);
	//print_color(str, num_of_cells);

	while (colors_is_correct(str, random_str, num_of_cells)) {
		print_mastermind(str, num_of_cells, how_many_bulls_mastermind(str, random_str, num_of_cells));
		mastermind_color_check(str, num_of_cells);
		print_color(random_str, num_of_cells);
		counter++;
	}

	printf_s("\nCorrect colors is: ");
	print_color(random_str, num_of_cells);
	printf_s("\nYou win!!\nNumber of attempts: %d\n", counter);
	_Exit(EXIT_SUCCESS);
	
	return 0;
}


