/*
 * Task6, task6.c
 * Purpose: write a program that computes the factorial of 10.
 *
 * @author Oleksandr Ushkarenko
 * @version 1.0 06/08/2021
 */

#include <stdio.h>

/*
 * Comment next directive to prevent using recursion 
 * in the function for calculating the factorial value of an integer. 
 */
#define _ENABLE_RECURSION

/*
 * The prototype of the function for calculating the factorial value of an integer.
 */
unsigned int factorial(unsigned int value);

/*
 * The main function of the program (i.e. entry point).
 * Demonstrates the use of factorial() function to calculate
 * the factorial of 10.
 *
 * @param argc the number of command line arguments
 * @param argv the array that contains passed command line arguments
 * @return 0 if successful
 */
int main(int argc, char *argv[])
{
        const int N = 10;
        unsigned int result;

        result = factorial(N);

        printf("Factorial of %d is %d.\n", N, result);

        return 0;
}

#ifdef _ENABLE_RECURSION
        /*
        * Recursive function for calculating the factorial value of an integer.
        *
        * @param value the integer number whose factorial is calculated
        * @return the factorial of the number passed to the function as an argument
        */
        unsigned int factorial(unsigned int value)
        {
                if(value == 0) {
                        return 1;
                }
                return value * factorial(value - 1);
        }
#else
        /*
        * The function calculates the factorial of a number.
        * No recursion is used.
        *
        * @param value the number whose factorial is calculated
        * @return the factorial of the number passed to the function as an argument
        */
        unsigned int factorial(unsigned int value)
        {
                unsigned int result = 1;
                unsigned int i;
                for(i = value; i > 1; i--) {
                        result *= i;
                }
                return result;
        }
#endif