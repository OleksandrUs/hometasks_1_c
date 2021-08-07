/*
    Task3, task3.c
    Purpose: write a function that converts the RGB888 data format to RGB565.

    @author Oleksandr Ushkarenko
    @version 1.0 06/08/2021
*/

#include <stdio.h>
#include <inttypes.h>

/*
 * The data structure is used to store the RGB888 data format components
 * such as red, green and blue values.
 */
typedef struct {
    // The value of red component.
    uint8_t r_val;
    // The value of green component.
    uint8_t g_val;
    // The value of blue component.
    uint8_t b_val;
} RGB888;

/*
 * The data structure (union) is used to store the RGB565 data format components
 * such as red, green and blue values.
 */
typedef union { 
    struct {
        // The value of blue component.
        uint16_t b_val : 5;
        // The value of green component.
        uint16_t g_val : 6;
        // The value of red component.
        uint16_t r_val : 5;
    };
    // This value contains all color components in certain bits:
    // r_val[15:11], g_val[10:5], b_val[4:0] 
    uint16_t color;
} RGB565;

/*
 * Function prototypes.
 */
RGB565 convert_rgb888_to_rgb565(RGB888 original_color);
void run_demo(void);

/*
 * The main function of the program.
 * Demonstration of using the function that converts 
 * the RGB888 data format to RGB565.
 * 
 * @param argc the number of command line arguments
 * @param argv the array that contains command line arguments
 * @return 0 if successful
 */
int main(int argc, char * argv[])
{
    run_demo();
    return 0;
}

/*
 * This function converts a value of RGB888 data format into RGB565 data format.
 *
 * @param original_color the variable of the RGB888 data format
 * @return the converted value to the RGB565 data format 
 */
RGB565 convert_rgb888_to_rgb565(RGB888 original_color)
{
    RGB565 converted_color;
    // Masks 0x1F and 0x3F below are not necessary in this case due to the internal
    // structurer of RGB888 and RGB565 are known. But, in general, it is safer in case if
    // the internal structure of this data formats are unkown.
    converted_color.r_val = (original_color.r_val >> 3) & 0x1F;
    converted_color.g_val = (original_color.g_val >> 2) & 0x3F;
    converted_color.b_val = (original_color.b_val >> 3) & 0x1F;
    return converted_color;
}

/*
 * This function demonstrates the use of the convert_rgb888_to_rgb565 function.
 * Test value received from a user represented in the RGB888 data format and passed into 
 * convert_rgb888_to_rgb565 function as an argument. The original value and the result
 * of its conversion to the RGB565 data format are printed.
 */
void run_demo(void)
{
    RGB888 orig_col;
    printf("Enter R value of RGB888 data format: ");
    fflush(stdout); 
    scanf("%hhd", &orig_col.r_val);
    printf("Enter G value of RGB888 data format: ");
    fflush(stdout); 
    scanf("%hhd", &orig_col.g_val);
    printf("Enter B value of RGB888 data format: ");
    fflush(stdout); 
    scanf("%hhd", &orig_col.b_val);

    RGB565 conv_col = convert_rgb888_to_rgb565(orig_col);
    
    printf("RGB888: [%d, %d, %d]\n", orig_col.r_val, 
                                     orig_col.g_val, 
                                     orig_col.b_val);

    printf("RGB565: [%d, %d, %d], %#.4x\n", conv_col.r_val,
                                            conv_col.g_val, 
                                            conv_col.b_val, 
                                            conv_col.color);
}
