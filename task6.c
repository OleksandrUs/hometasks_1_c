/*
    Task6, task6.c
    Purpose: write a program that computes the factorial of 10.

    @author Oleksandr Ushkarenko
    @version 1.0 06/08/2021
*/

#include <stdio.h>

/*
 * The function calculates the factorial of a number.
 * Recursion is used in function implementation.
 *
 * @param value the number whose factorial is calculated
 * @return the factorial of the number passed to the function as an argument
 */
unsigned int factorial(unsigned int value)
{
    if(value == 0) {
        return 1;
    }
    else {
        return value * factorial(value - 1);
    }
}

/*
 * The main function of the program (i.e. entry point).
 * Demonstrates the use of factorial() function to calculate
 * the factorial of 10.
 *
 * @param argc the number of command line arguments
 * @param argv the array that contains passed command line arguments
 * @return 0 if successful
 */
int main(int argc, char * argv)
{
    const int N = 10;
    unsigned int result;

    result = factorial(N);

    printf("Factorial of %d is %d.\n", N, result);

    return 0;
}