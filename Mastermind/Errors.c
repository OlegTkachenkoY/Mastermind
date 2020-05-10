#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "Bulls_and_Cows_Source.h"  //Import function from file: Bulls_and_Cows_Source.h
#include "Mastermind.h"             //Import function from file: Mastermind.h



//Point of entry

int check_errors_bulls_and_cows(int* arr) {
    int num, i = 0;
    printf_s("Pleas input num: ");
    num = incorrect_character_error();

    fflush(stdin);

    quantity_error(num);
    �onvert_num_to_arr(arr, num);
    tautology_error(arr);

}

int mastermind_num_check() {
    int num;
    printf_s("How many colors should there be: ");
    num = incorrect_character_error();

    /*This function throws an error when the user enters a number less than 4 or more in 10.
    If the number is less than 4 then the game will be too easy and
    if more than 10 then the game may be extended for hours.*/
    while (num < 4 || num > 10){
        printf_s("Error: You went beyond the border.\n");
        printf_s("Please try again(Min. allowed 4, max. allowed 10): ");
        num = incorrect_character_error();
    }
    return num;
}

int mastermind_color_check(char* str, int num) {
    char symbol;
    
    for (int i = 0; i < num; i++) {
        str[i] = color_error(i+1);
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
        printf_s("Try again: ");

        return incorrect_character_error();
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

/*
This function checks the entered color of the available colors:
    Y-Yellow
    G-Green
    R-Red
    P-Pink
    B-Blue
    O-Orange.
If the entered color is not in range, an error occurs.
The program asks you to enter the color again.
*/
int color_error(int counter) {
    while (getchar() != '\n');
    char color;

    printf_s("Pleas input %d color: ", counter);
    scanf_s("%c", &color);
    color = tolower(color);

    if (!(color == 'y' || color == 'g' || color == 'r' || color == 'p' || color == 'b' || color == 'o')) {
        printf_s("\nError: This color is not used in the game.\n\n");
        printf_s("Available colors:\nY-Yellow\nG-Green\nR-Red\nP-Pink\nB-Blue\nO-Orange.\n\n");
        return color_error(counter);
    }
    
    return color;
}