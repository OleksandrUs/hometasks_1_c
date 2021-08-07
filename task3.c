/*
 * Task3, task3.c
 * Purpose: write a function that converts the RGB888 data format to RGB565.
 *
 * @author Oleksandr Ushkarenko
 * @version 1.0 06/08/2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define CMD_LINE_ARGS_COUNT 4
#define R_INDEX 1
#define G_INDEX 2
#define B_INDEX 3

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
RGB888 parse_cmd_line_args(char * argv[]);
RGB888 get_rgb888_from_user(void);
void run_demo(int argc, char *argv[]);
void print_info(RGB888 orig_color, RGB565 conv_color);

/*
 * The main function of the program.
 * Demonstration of using the function that converts 
 * the RGB888 data format to RGB565.
 * 
 * @param argc the number of command line arguments
 * @param argv the array that contains command line arguments
 * @return 0 if successful
 */
int main(int argc, char *argv[])
{
        run_demo(argc, argv);
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
 * The function processes command line arguments to extract R, G and B
 * values and puts them in the variable of the RGB888 data format.
 *
 * @param argv the array that contains command line arguments
 * @return the value of the RGB888 data format
 */
RGB888 parse_cmd_line_args(char *argv[])
{
        RGB888 orig_col;
        orig_col.r_val = atoi(argv[R_INDEX]);
        orig_col.g_val = atoi(argv[G_INDEX]);
        orig_col.b_val = atoi(argv[B_INDEX]);
        return orig_col;
}

/*
 * The function gets from a user the R, G and B values and puts them
 * in the variable of the RGB888 data format.
 *
 * @return the value of the RGB888 data format
 */
RGB888 get_rgb888_from_user(void)
{
        RGB888 orig_col;
        printf("Enter R value [0-255]: ");
        fflush(stdout); 
        scanf("%hhd", &orig_col.r_val);
        printf("Enter G value [0-255]: ");
        fflush(stdout); 
        scanf("%hhd", &orig_col.g_val);
        printf("Enter B value [0-255]: ");
        fflush(stdout); 
        scanf("%hhd", &orig_col.b_val);
        return orig_col;
}

/*
 * The function prints the components of the RGB888 and RGB565 data types
 * in the format [R, G, B]. For the RGB565 data format the value in 
 * hexadecimal format is also printed.
 * 
 * @param orig_color the value of the RGB888 data format
 * @param orig_color the value of the RGB565 data format
 */
void print_info(RGB888 orig_col, RGB565 conv_col)
{
        printf("RGB888: [%d, %d, %d]\n", orig_col.r_val, 
                                        orig_col.g_val, 
                                        orig_col.b_val);

        printf("RGB565: [%d, %d, %d], %#.4x\n", conv_col.r_val,
                                                conv_col.g_val, 
                                                conv_col.b_val, 
                                                conv_col.color);
}

/*
 * This function demonstrates the use of the convert_rgb888_to_rgb565 function.
 * Test value received from a user represented in the RGB888 data format and passed into 
 * convert_rgb888_to_rgb565 function as an argument. The original value and the result
 * of its conversion to the RGB565 data format are printed.
 * 
 * @param argc the number of command line arguments
 * @param argv the array that contains command line arguments
 */
void run_demo(int argc, char *argv[])
{
        RGB888 orig_col;

        if(argc == CMD_LINE_ARGS_COUNT) {
                orig_col = parse_cmd_line_args(argv);
        } else {
                orig_col = get_rgb888_from_user();
        }

        RGB565 conv_col = convert_rgb888_to_rgb565(orig_col);
        
        print_info(orig_col, conv_col);
}
