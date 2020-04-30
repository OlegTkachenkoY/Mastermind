#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "Bulls_and_Cows_Source.h"  //Import function from file: Project_Source.h


/*
Point of entry
*/
int check_errors(int* arr) {
    int num;
    num = incorrect_character_error();

    fflush(stdin);

    quantity_error(num);

    ñonvert_num_to_arr(arr, num);
    tautology_error(arr);

}

/*
This function checks that the number you enter does not contain any characters.
If the entered data contains characters, the program stops working.
If not, the input is returned to the entry point.
*/
int incorrect_character_error() { ///???
    int num;

    printf_s("Pleas input num: ");

    if (scanf_s("%d", &num) != 1) {
        while (getchar() != '\n');
        printf_s("Error: incorrect character.\n");
        
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
        _Exit(EXIT_SUCCESS);
    }
    else if (counter < 4) {
        printf_s("Error: The number is less than four digit number.\n");
        _Exit(EXIT_SUCCESS);
    }
}
