/*
 * Task4, task4.c
 * Purpose: write a program that gets two values from a user: height and width of a rectangle
 * in meters and calculates and prints the perimeter and the area of the rectangle in inches.
 *
 * @author Oleksandr Ushkarenko
 * @version 1.0 06/08/2021
 */

#include <stdio.h>
#include <math.h>

/*
 * The number of inches in 1 meter.
 */
#define INCHES_IN_METER 39.3701

/*
 * Function prototypes.
 */
double get_rect_height(void);
double get_rect_width(void);
double rect_perimeter_inches(const double height, const double width);
double rect_area_inches(const double height, const double width);

/*
 * The main function of the program.
 * Gets two values from a user - height and width of a rectangle in meters,
 * calculates and prints the perimeter and the area of the rectangle in inches.
 * 
 * @param argc the number of command line arguments
 * @param argv the array that contains passed command line arguments
 * @return 0 if successful
 */
int main(int argc, char *argv[])
{
        double rect_height = 0;
        double rect_width = 0;
        double perimeter = 0;
        double area = 0;
        
        rect_height = get_rect_height();
        rect_width = get_rect_width();

        if((rect_height >= 0) && (rect_width >= 0)) {
                perimeter = rect_perimeter_inches(rect_height, rect_width);
                area = rect_area_inches(rect_height, rect_width);
                
                printf("The perimeter of the rectangle is %.2lf inches.\n", perimeter);
                printf("The area of the rectangle is %.2lf square inches.\n", area);
        } else {
                printf("Height and width of a rectangle must be positive numbers!\n");
        }

        return 0;
}

/*
 * The function gets the height of the rectangle from a user.
 *
 * @return the height of the the rectangle in meters
 */
double get_rect_height(void)
{
        double height = 0;

        printf("Please, enter the height of the rectangle (in meters): ");
        fflush(stdout);
        scanf("%lf", &height);

        return height;
} 

/*
 * The function gets the width of the rectangle from a user.
 *
 * @return the width of the the rectangle in meters
 */
double get_rect_width(void)
{
        double width = 0;

        printf("Please, enter the width of the rectangle (in meters): ");
        fflush(stdout);
        scanf("%lf", &width);

        return width;
} 

/*
 * The function calculates the perimeter of the rectangle in inches.
 *
 * @param height the height of the rectangle in meters
 * @param width the width of the rectngle in meters
 * @return the perimeter of the the rectangle in inches
 */
double rect_perimeter_inches(const double height, const double width)
{
        return 2 * (height + width) * INCHES_IN_METER;
}

/*
 * The function calculates the area of the rectangle in square inches.
 *
 * @param height the height of the rectangle in meters
 * @param width the width of the rectngle in meters
 * @return the area of the the rectangle in inches
 */
double rect_area_inches(const double height, const double width)
{
        return height * width * pow(INCHES_IN_METER, 2);
}
