#include <stdio.h>
#include <time.h>
#include <stdlib.h>


//****************************************************************

/*
Since there is no function in C programming language that generates numbers without repetition
(Most likely I just don't know such a function), I had to make this decision. At the beginning,
an array of 10 numbers from 0 to 10 is given. Then in the (wava) function, this array is mixed
arbitrarily, and in the (abva) function, we take the first 4 numbers.
*/
int shuffle(int* array, int n) { 
    srand(time(NULL));
    if (n > 1)
    {
        for (int i = 0; i < n - 1; i++)
        {
            int j = i + rand() % 10 - i;
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}

int random_gen(int* arr) {

    int arr_tmp[] = { 0,1,2,3,4,5,6,7,8,9 };

    shuffle(arr_tmp, 10);

    for (int i = 0; i < 4; i++) {
        arr[i] = arr_tmp[i];
    }
}

//****************************************************************

/*
This function equals the numbers we enter are the same. If they are the same, then the function
returns 1 is true. If not the same at least in one integer, the function terminates and returns 0,
which is false.
*/
int check_num(int* arr) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (arr[i] == arr[j] && i!=j) {
                return 1;
            }
        }
    }
    return 0;
}

//****************************************************************

/*
This function splits the entered number into single, small numbers. How it works:
Entered: 1234
Step 1: 1234% 10 = 4 Writed this number at the end of the array
Step 2: 1234/10 = 123.4 Since we have entered an integer type then the number is 123
Step 3: Go back to step 1 four times

123 = {-,-,-,4}
12  = {-,-,3,4}
1   = {-,2,3,4}
-   = {1,2,3,4}

*/
int сonvert_num_to_arr(int *arr,int num) {
    for (int i = 3; i >= 0; i--) {
       arr[i] = num % 10;
       num = num / 10;
    }
}

/*
This function makes a four-digit number from array.
For example {1,4,2,1} = 1421
How it works:
Step 1: Create a Num number that will be 0
Step 2: Multiply Num by 10 and add the first element of the array (num = num * 10 * 1)
Step 3: Repeat this procedure 4 times.

1
14
142
1424

Update 1:
This function was used in previous versions, it should not be deleted, it may be necessary in the next ones
*/
int convert_arr_to_num(int* arr) {
    int num=0;
    for (int i = 0; i < 4; i++) {
        num = num * 10 + arr[i];
    }

    return num;
}

//****************************************************************

/*
This function checks the number of cows. Cows are numbers that are out of place.
Example:
Generated number: 1234
Number entered: 5712
Cows: 2
These are the numbers * 1 * and * 2 *

How this function works:
The function equals the number of the generated number and that entered by the user
if they coincide while not standing in their place then the counter is increased by 1.
*/
int how_many_cows(int *arr, int * random_arr) {
    int counter = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (arr[i] == random_arr[j] && i!= j) {
                counter++;
            }
       }
    }
    return counter;
}

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
int how_many_bulls(int* arr, int* random_arr) {
    int counter = 0;
    for (int i = 0; i < 4; i++) {
        if (arr[i] == random_arr[i]) {
            counter++;
        }
    }
    return counter;
}

/*
The function checks whether the numbers entered are the same. If the number differs, the function returns a value of 0, ie false.
*/
int num_is_correct(int* arr, int* random_arr) {
    for (int i = 0; i < 4; i++) {
        if (arr[i] != random_arr[i]) {
            return 1;
        }
    }
    return 0;
}

//****************************************************************
/*
Function for easy output of values
*/
void print(int* arr, int bulls, int cows) {
    printf_s("\nYour number: ");
    for (int i = 0; i < 4; i++) {
        printf_s("%d", arr[i]);
    }
    printf_s("\nBulls: %d\nCows:  %d\n", bulls, cows);
}

//****************************************************************
/*
This function determines the number of digits in a given number. This is determined by simple arithmetic action:
1) The number is divisible by 10 without fractions(123 // 10 = 12).
2) Check if the new number is 0.
3) If the new number is zero then go to step 4. if not step 1
4) End of algorithm.
*/
int counter_of_number(int num) {
    int counter = 0;
    while (num != 0){
        num = num / 10;
        counter++;
    }
    return counter;
}