/*
 * Task5, task5.c
 *  Purpose: write a program that computes the perimeter and the area of a
 * circle with a radius of 6.
 *
 * @author Oleksandr Ushkarenko
 * @version 1.0 06/08/2021
 */

/*
 * This definition allows to use useful mathematical constants, such as PI etc.
 */
#define _USE_MATH_DEFINES

#include <stdio.h>
#include <math.h>

/*
 * Function prototypes.
 */
static inline double circle_perimeter(double radius);
static inline double circle_area(double radius);
void print_circle_params(double perimeter, double area);

/*
 * The main function of the program.
 * Computes and prints the perimeter and the area of a circle with a radius of 6.
 * 
 * @param argc the number of command line arguments
 * @param argv the array that contains passed command line arguments
 * @return 0 if successful
 */
int main(int argc, char *argv[])
{
        const double RADIUS = 6;

        double perimeter = circle_perimeter(RADIUS);
        double area = circle_area(RADIUS);

        print_circle_params(perimeter, area);

        return 0;
}

/*
 * The function computes the perimeter of a circle with a specified radius.
 *
 * @param radius the radius of a circle
 * @return the perimeter of a circle with a specified radius
 */
static inline double circle_perimeter(double radius)
{
        return 2 * M_PI * radius;
} 

/*
 * The function computes the area of a circle with a specified radius.
 * Due to the fact, that this function is quite simple and short, it can
 * be more efficient to use it as inline.
 * 
 * @param radius the radius of a circle
 * @return the area of a circle with a specified radius
 */
static inline double circle_area(double radius)
{
        return M_PI * pow(radius, 2);
}

/*
 * The function prints the perimeter and the area of the circle in the console window.
 * Because this function is quite simple and short, it can be
 * more efficient to use it as inline.
 * 
 * @param perimeter the perimeter of a circle
 * @param area the area of a circle
 */
void print_circle_params(double perimeter, double area)
{
        printf("The perimeter of a circle with a radius of 6 is %.2f units of length.\n", perimeter);
        printf("The area of a circle with a radius of 6 is %.2f units of area.\n", area);
}