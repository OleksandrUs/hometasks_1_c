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
#include <inttypes.h>

/*
 * The number of inches in 1 meter.
 */
#define INCHES_IN_METER 39.3701

/*
 * The codes that describe the results of cheking rectangle parameters
 * received from the user.
 */
#define VALID 0
#define INVALID -1

/*
 * The data structure is used to store the information about rectangle,
 * such as height and width.
 */
typedef struct {
        double height;
        double width;
} RECT;

/*
 * Function prototypes.
 */
RECT build_rect(void);
double get_rect_height(void);
double get_rect_width(void);
static inline double calc_rect_perimeter_inches(const RECT *rect);
static inline double calc_rect_area_inches(const RECT *rect);
void print_rect_params(double perimeter, double area);
int validate_rect(const RECT *rect);

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
        RECT rect;
        double perimeter = 0;
        double area = 0;

        rect = build_rect();    

        if(validate_rect(&rect) == VALID) {
                perimeter = calc_rect_perimeter_inches(&rect);
                area = calc_rect_area_inches(&rect);
                print_rect_params(perimeter, area);
        } 

        return 0;
}

/*
 * The function creates the instance of RECT structure and fills its fields by
 * receiving all the necessary values from the user.
 * 
 * @return the instance of RECT data structure
 */
RECT build_rect(void)
{
        RECT rect;
        rect.height = get_rect_height();
        rect.width = get_rect_width();
        return rect;
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
 * Because this function is quite simple and short, it can be
 * more efficient to use it as inline.
 *
 * @param the pointer to the instance of the RECT data structure
 * @return the perimeter of the the rectangle in inches
 */
static inline double calc_rect_perimeter_inches(const RECT *rect)
{
        return 2 * (rect->height + rect->width) * INCHES_IN_METER;
}

/*
 * The function calculates the area of the rectangle in square inches.
 * Because this function is quite simple and short, it can be
 * more efficient to use it as inline.
 * 
 * @param rect the pointer to the instance of the RECT data structure
 * @return the area of the the rectangle in inches
 */
static inline double calc_rect_area_inches(const RECT *rect)
{
        return rect->height * rect->width * pow(INCHES_IN_METER, 2);
}

/*
 * The function prints the perimeter and the area of the rectangle in square inches.
 *
 * @param perimeter the perimeter of the rectangle
 * @param area the area of the rectangle
 */
void print_rect_params(double perimeter, double area)
{
        printf("The perimeter of the rectangle is %.2lf inches.\n", perimeter);
        printf("The area of the rectangle is %.2lf square inches.\n", area);
}

/*
 * The function checks if the height and the width of the rectangle
 * are not negative. If one af the fields of the structure is negative,
 * the information message for user will be printed.
 *
 * @param rect the pointer to the instance of the RECT data structure to be checked
 * @return VALID if height and width of the rectangle are not negative, 
 * otherwise return IVNALID 
 */
int validate_rect(const RECT *rect)
{
  if((rect->height >= 0) && (rect->width >= 0)) {
          return VALID;
  } else {
        printf("Height and width of a rectangle must be positive numbers!\n");
  }
  return INVALID;
}