#include "Bulls_and_Cows_Source.h"
#include "Mastermind.h"
#include "Errors.h"

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

int start_mastermind() {
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
}

int start_bulls_and_cows() {
	int counter = 1;
	int random_arr[4];
	int arr[4];

	random_gen(random_arr);
	check_errors_bulls_and_cows(arr);
	//printf_s("%d\n", convert_arr_to_num(random_arr));


	while (num_is_correct(arr, random_arr)) { //The cycle will end when the number is assumed to be the same as that generated
		print(arr, how_many_bulls(arr, random_arr), how_many_cows(arr, random_arr));
		check_errors_bulls_and_cows(arr);
		counter++;    //counter = counter + 1;
	}


	printf_s("\nCorrect number is: ");
	for (int i = 0; i < 4; i++) {
		printf_s("%d", arr[i]);
	}
	printf_s("\nYou win!!\nNumber of attempts: %d\n", counter);
	_Exit(EXIT_SUCCESS);
}


int main() {
	int choice, counter = 1;

	
	while (counter){
		printf_s("1 - Start Mastermind Game.\n2 - Start Bulls and Cows Game\n\nInput: ");
		scanf_s("%d", &choice);

		if (choice == 1) {
			start_mastermind();
		}
		else if (choice == 2) {
			start_bulls_and_cows();
		}
		else {
			printf_s("Error: The input command does not exist.\n");
		}

		while (getchar() != '\n');
		printf_s("Try again?(1/0): ");
		scanf_s("%d", &counter);
	}

	
	return 0;
}


