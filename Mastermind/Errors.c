#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "Bulls_and_Cows_Source.h"  //Import function from file: Project_Source.h
#include "Mastermind.h"



//Point of entry

int check_errors_bulls_and_cows(int* arr) {
    int num;
    printf_s("Pleas input num: ");
    num = incorrect_character_error();

    fflush(stdin);

    quantity_error(num);

    ñonvert_num_to_arr(arr, num);
    tautology_error(arr);

}


int mastermind_num_check() {
    int num;

    num = incorrect_character_error();
    limit_error(num);


    return num;
}

int mastermind_color_check(char* str, int num) {
    for (int i = 0; i < num; i++) {

    }

}

//****************************************************************
/*
This function checks that the number you enter does not contain any characters.
If the entered data contains characters, the program stops working.
If not, the input is returned to the entry point.
*/
int incorrect_character_error() { ///???
    int num;

    
    if (scanf_s("%d", &num) != 1) {
        while (getchar() != '\n');
        printf_s("Error: incorrect character.\n");
        printf_s("Try again:");
        
        incorrect_character_error();
        //_Exit(EXIT_SUCCESS);
    }
    return num;
}
/*
 do
    {
        printf_s("Pleas input num: ");
        indicator = scanf_s("%d", &num);

        while (getchar() != '\n');

        if (indicator != 1) {
            printf_s("Error: incorrect character.\n\n");
        }
    } while (indicator != 1);
*/

/*
This function checks for tautology in the number.
If a tautology exists, the program terminates.
Otherwise, the program returns to the entry point.

Examples of tautology:

        1223
        3356
        2245
        4455
*/
int tautology_error(int* arr) {
    if (check_num(arr)) {
        printf_s("Error: The numbers should not be repeated.\n");
        printf_s("Try again:");
        _Exit(EXIT_SUCCESS);
    }
}

/*
This function checks the number of items in a number. The very amount is learned by the function counter_of_number() Then comes the check:
If less than or greater then the program throws an error.
If the number has 4 digits then it has been checked.
*/
int quantity_error(int num) {
    int counter = counter_of_number(num);

    if (counter > 4) {
        printf_s("Error: The number greater than four digit number.\n");
        printf_s("Try again:");
        _Exit(EXIT_SUCCESS);
    }
    else if (counter < 4) {
        printf_s("Error: The number is less than four digit number.\n");
        printf_s("Try again:");
        _Exit(EXIT_SUCCESS);
    }
}

/*This function throws an error when the user enters a number less than 4 or more in 10.
If the number is less than 4 then the game will be too easy and 
if more than 10 then the game may be extended for hours.
*/
int limit_error(int num) {
    if (num < 4 || num > 10) {
        printf_s("Error: You went beyond the border.\n");
        printf_s("Please try again(Min. allowed 4, max. allowed 10): ");
        _Exit(EXIT_SUCCESS);
    }
}