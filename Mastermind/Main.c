#include "Bulls_and_Cows_Source.h"
#include "Mastermind.h"
#include "Errors.h"

#include <stdio.h>
#include <string.h>
#include <malloc.h>




int main() {

	int num_of_cells;
	char *random_str, *str;
	
	num_of_cells = check_errors_mastermind();
	

	random_str = (char*)malloc(num_of_cells * sizeof(int));
	str = (char*)malloc(num_of_cells * sizeof(int));
	
	color_generator(random_str, num_of_cells);
	//print_color(random_str,num_of_cells);
	
	mastermind_color_check(str, num_of_cells);
	


	return 0;
}



/*
int main() {

	int counter = 1;
	int random_arr[4];
	int arr[4];

	random_gen(random_arr);


	check_errors(arr);



	//printf_s("%d\n", convert_arr_to_num(random_arr));


	while (num_is_correct(arr, random_arr)){ //The cycle will end when the number is assumed to be the same as that generated
		print(arr, how_many_bulls(arr, random_arr), how_many_cows(arr, random_arr));
		check_errors(arr);
		counter++;    //counter = counter + 1;
	}


	printf_s("\nCorrect number is: ");
	for (int i = 0; i < 4; i++) {
		printf_s("%d", arr[i]);
	}
	printf_s("\nYou win!!\nNumber of attempts: %d\n",counter);


	return 0;
}
*/
