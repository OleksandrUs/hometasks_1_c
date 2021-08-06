/*
    Task7, task7.c
    Purpose: write a program that prints all the integer numbers between 1 to 500
    which are divisible by a number received from a user.

    @author Oleksandr Ushkarenko
    @version 1.0 06/08/2021
*/

#include <stdio.h>
#include <stdlib.h>

/*
 * The index of an integer number (divisor) received from a user
 * through the command line arguments and stored in array argv, which is
 * the second argument in main function.
 */
#define DIVISOR_INDEX 1

/*
 * The number of command line arguments in case the user 
 * passes an integer number (divisor) through them.
 */
#define CMDLINE_ARGUMENTS_NUM 2

/*
 * The function reads an integer number (divisor) received from a user.
 * The divisor can be received from a user by 2 ways: througt the command line
 * argumenst when the program runs, or if there hasn't been command line 
 * arguments passed, the user can enter the divisor in the console after the
 * program starts.
 * 
 * @return the divisor entered by a user in the console
 */
int get_divisor_from_user(int argc, char * argv[])
{
    int value = 0;

    if(argc == CMDLINE_ARGUMENTS_NUM) {
       value = atoi(argv[DIVISOR_INDEX]);
    }
    else {
        printf("Please, enter the divisor: ");
        fflush(stdout);
        scanf("%d", &value);
    }
    return value;
}

/*
 * The function prints in a column the list of integer numbers 
 * from a specific range that are divisible by a number received from a user.
 * 
 * @param divisor a number received from a user
 * @param begin_num the begining of the range of numbers
 * @param end_num the ending of the range of numbers
 */
void print_numbers(const int divisor, const int begin_num, const int end_num)
{
    if(divisor != 0) {
         for(int i = begin_num; i <= end_num; i++) {
            if((i % divisor) == 0){
                printf("%d\n", i);
             }
        }
    }
    else {
        printf("The divisor mustn't be 0!\n");
    }
}

/*
 * The main function of the program.
 * Prints all the integer numbers between 1 to 500 
 * which are divisible by a number received from a user.
 * 
 * @param argc the number of command line arguments
 * @param argv the array that contains passed command line arguments
 * @return 0 if successful
 */
int main(int argc, char * argv[])
{
    const int RANGE_BEGIN = 1;
    const int RANGE_END = 500;
    int divisor;

    divisor = get_divisor_from_user(argc, argv);

    if(divisor != 0) {
        printf("The integer numbers between %d to %d which are divisible by %d:\n", RANGE_BEGIN, RANGE_END, divisor);
        print_numbers(divisor, RANGE_BEGIN, RANGE_END);
    }
    else {
        printf("The divisor mustn't be 0!\n");
    }

    return 0;
}