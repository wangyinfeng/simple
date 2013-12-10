/*====================================================================
 * Description: Seems you know little about the float, double
 * DATE: 2013/12/10
 * Modify:
 * Conclusion:
===================================================================*/
/* include */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/* Macro definition */
#define false           0
#define true            1

int
main(int argc, char **argv)
{
        float a = 0.7;
//    if(0.7 > a)
    if(0.7 > 0.7f) /* double constant 0.7 larger than the float a - why? */
        /* the conversion from decimal values to binary floating point values as inherently lossy */
        /* How to compare two real number? */
            /* One solution is use absolute error, but only work for the number around the 0 or 1,
             * not work for the too small or to large numbers
             * if (fabs(a-b)<epsilon) */

            /* Another way is use relative error, if b is not ZERO.
             * if (fabs((a-b)/b)<epsilon) */
        printf("Hi\n");
    else
        printf("Hello\n");

    /* By default, the real number is double type */
    /* Float guarantee 6 significant figures; double guarantee 10 significant figures;
     * and long double guarantee no less than significant figures */
    /* On 64 bits Linux, 3.14f is float, 4 bytes; 3.14 is double, 8 bytes, 3.14l(not 3.141) is long double, 16 bytes */
    printf("%d, %d, %d\n", sizeof(3.14f), sizeof(3.14), sizeof(3.14l));
    return 0;
}

