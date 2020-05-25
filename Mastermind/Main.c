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

	printf_s("Purpose of the game\nThe user wins the round if he breaks the code with 12 or less attempts.\nThe user loses if it fails to crack the code in 12 attempts.\n\nTo try to guess\nSelect the number of guessing spots. (4 to 10)\nLack of color.\n\nIf you do not guess\nThe program evaluates the attempt.The user continues to guess until\n technical support until the code is cracked or he uses all 12 attempts.\n\nIf guessing\nIf the generated colors match what you entered, then you won.\n\nAvailable colors:\nY-Yellow\nG-Green\nR-Red\nP-Pink\nB-Blue\nO-Orange.\n\n");

	num_of_cells = mastermind_num_check();


	random_str = (char*)malloc(num_of_cells * sizeof(int));
	str = (char*)malloc(num_of_cells * sizeof(int));

	color_generator(random_str, num_of_cells);


	mastermind_color_check(str, num_of_cells);

	while (colors_is_correct(str, random_str, num_of_cells)) {
		print_mastermind(str, num_of_cells, how_many_bulls_mastermind(str, random_str, num_of_cells));
		mastermind_color_check(str, num_of_cells);
		counter++;
		if (counter > 12) {
			printf_s("\nCorrect colors is: ");
			print_color(random_str, num_of_cells);
			printf_s("\nYou lose!!\n");
			return 0;
		}

	}

	printf_s("\nCorrect colors is: ");
	print_color(random_str, num_of_cells);
	printf_s("\nYou win!!\nNumber of attempts: %d\n", counter);
	_Exit(EXIT_SUCCESS);
	
	return 0;
}


