/*
    Task2, task2.c
    Purpose: write the swap16, swap32, swap64 functions that swap bytes in 
    uint16_t, uint32_t, and uint64_t (endianness conversions).

    @author Oleksandr Ushkarenko
    @version 1.0 06/08/2021
*/

#include <stdio.h>
#include <inttypes.h>

/*
 * Function prototypes.
 */
uint16_t swap16(uint16_t value);
uint32_t swap32(uint32_t value);
uint64_t swap64(uint64_t value);
void run_demo(void);

/*
 * The main function of the program.
 * Demonstration of using the functions swap16, swap32, swap64 which swap bytes in 
 * variables of the uint16_t, uint32_t and uint64_t data types (endianness conversions).
 * 
 * @param argc the number of command line arguments
 * @param argv the array that contains passed command line arguments
 * @return 0 if successful
 */
int main(int argc, char * argv[])
{
    run_demo();
    return 0;
}

/*
 * The function changes the sequence of bytes in a variable of uint16_t data type.
 * The most significant byte of a 16-bit integer variable becomes
 * the least significant byte and vice versa.
 * 
 * @param value the original number
 * @return new value with swapped bytes 
 */
uint16_t swap16(uint16_t value)
{
    return ((value >> 8) | ((value & 0x00FF) << 8));
}

/*
 * The function changes the sequence of bytes in a variable of uint32_t data type.
 * The most significant byte of a 32-bit integer variable becomes
 * the least significant byte and vice versa.
 * 
 * @param value the original number
 * @return new value with changed byte order 
 */
uint32_t swap32(uint32_t value)
{
    uint32_t new_value = 0;
    new_value = ((value & 0xFF000000) >> 24) |
                ((value & 0x00FF0000) >> 8) |
                ((value & 0x0000FF00) << 8) |
                ((value & 0x000000FF) << 24);
    return new_value;
}

/*
 * The function changes the sequence of bytes in a variable of uint64_t data type.
 * The most significant byte of a 64-bit integer variable becomes
 * the least significant byte and vice versa.
 * 
 * @param value the original number
 * @return new value with changed byte order 
 */
uint64_t swap64(uint64_t value)
{   
    uint64_t new_value = 0;
    new_value = ((value & 0xFF00000000000000) >> 56) |
                ((value & 0x00FF000000000000) >> 40) |
                ((value & 0x0000FF0000000000) >> 24) |
                ((value & 0x000000FF00000000) >> 8) |
                ((value & 0x00000000FF000000) << 8) |
                ((value & 0x0000000000FF0000) << 24) |
                ((value & 0x000000000000FF00) << 40) |
                ((value & 0x00000000000000FF) << 56);
    return new_value;
}

/*
 * This function demonstrates the use of the swap16, swap32 and swap64 functions.
 * Test values represented in hexadecimal format are used.
 * Three messages are printed for each case: the original value, the value 
 * after the first function call, and the value after the second function call. 
 * The original value and the value obtained after the second function call
 * must be the same.
 */
void run_demo(void)
{
    printf("\nDemonstration of the swap16, swap32 and swap64 function calls:\n\n");
    
    // swap16 function calls
    uint16_t  var_16_bit = 0x3210;
    printf("-------------swap16 function call--------------\n");
    printf("Original value: %#.4x\n", var_16_bit);
    var_16_bit = swap16(var_16_bit);
    printf("New value after first swap16 function call: %#.4x\n", var_16_bit);
    var_16_bit = swap16(var_16_bit);
    printf("New value after second swap16 function call: %#.4x\n\n", var_16_bit);

    // swap32 function calls
    uint32_t  var_32_bit = 0x76543210;
    printf("-------------swap32 function call--------------\n");
    printf("Original value: %#.8x\n", var_32_bit);
    var_32_bit = swap32(var_32_bit);
    printf("New value after first swap32 function call: %#.8x\n", var_32_bit);
    var_32_bit = swap32(var_32_bit);
    printf("New value after second swap32 function call: %#.8x\n\n", var_32_bit);

    // swap64 function calls
    uint64_t  var_64_bit = 0xfedcba9876543210;
    printf("-------------swap64 function call--------------\n");
    printf("Original value: 0x%.16" PRIx64 "\n", var_64_bit);
    var_64_bit = swap64(var_64_bit);
    printf("New value after first swap64 function call: 0x%.16" PRIx64 "\n", var_64_bit);
    var_64_bit = swap64(var_64_bit);
    printf("New value after second swap64 function call: 0x%.16" PRIx64 "\n\n", var_64_bit);
}
