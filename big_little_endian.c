/*====================================================================
 * Description: Approach to check the current machine is big endian or
 *		        little endian. And conver, use function pointer.
 *		        Little endian: the low number stored at the low address
 *		        Bit endian: the high number stored at the low address
 *		        Example: 0x12345678
 *		        Little endian: 
 *		        78 56 34 12 address low->high
 *		        Big endian:
 *		        12 34 56 78 address low->high
 * DATE: 2013/10/25
 * Modify: 2013/10/29
 * Conclusion: More than one approach to get the result
===================================================================*/
/* include */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Macro definition */
#define true            1
#define false           0

/* mess the union and enum... */
typedef union TEST {
    unsigned char c[4];
    unsigned int b;
}TEST;

typedef int (*fpConvert)(const int);

int
convert_1(const int a)
{
    int b = 0;
    int size = sizeof(int);
    int i;
    for (i=1; i<=size; i++){
        b |= ((a>>(8*(size-i)))&0xff) << (8*(i-1));
    }
    return b;
}
int 
convert_2(const int a)
{
    TEST b;
    int i;
    unsigned char tmp;
    b.b = a;
    for (i=0; i<(4/2); i++){
        tmp = b.c[i];
        b.c[i] = b.c[4-i-1];
        b.c[4-i-1] = tmp;
    }
    return b.b;
}

int
convert_3(const int num)
{
    /* not much than the approach 1 */
    int swapped;
    swapped = ((num>>24)&0xff) | // move byte 3 to byte 0
                    ((num<<8)&0xff0000) | // move byte 1 to byte 2
                    ((num>>8)&0xff00) | // move byte 2 to byte 1
                    ((num<<24)&0xff000000); // byte 0 to byte 3

    return swapped;
}

int
convert_4(const int a)
{
    int val;
    val = ((a << 8) & 0xFF00FF00 ) | ((a >> 8) & 0xFF00FF ); 
    return (val << 16) | (val >> 16);
}

int
convert_approach(fpConvert convert, const int a)
{
    return convert(a);
}

int
main(int argc, char **argv)
{
    TEST test, result;
    int i;
    test.b = 0x12345678;
    if (test.c[0] == 0x12) {
        printf("Current machine is Big Endian\n");
        printf("In memory:\n");
        for (i=0; i<4; i++) {
            printf("%02x:\t%p\n", test.c[i], test.c+i);
        }
        /*
        printf("Convert to Little endian\n");
        convert(test.b, &result.b);
        for (i=0; i<4; i++) {
            printf("%02x:\t%p\n", result.c[i], result.c+i);
        }
        */
    }
    else {
        printf("Current machine is Little Endian\n");
        printf("In memory:\n");
        for (i=0; i<4; i++) {
            printf("%02x:\t%p\n", test.c[i], test.c+i);
        }
        printf("Convert to Big endian\n");
        //result.b = convert_approach(convert_2, test.b);
        //result.b = convert_approach(convert_1, test.b);
        //result.b = convert_approach(convert_3, test.b);
        result.b = convert_approach(convert_4, test.b);
        for (i=0; i<4; i++) {
            printf("%02x:\t%p\n", result.c[i], result.c+i);
        }
    }
    return 0;
}

