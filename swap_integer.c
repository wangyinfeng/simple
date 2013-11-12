/*====================================================================
 * Description: swap the integer, not use temporary variable
 * DATE: 2013/11/12
 * Modify:
 * Conclusion:
===================================================================*/
/* include */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Macro definition */
#define true            1
#define false           0

#define SWAP(a,b)   (a) ^= (b), (b) ^= (a), (a) ^= (b)

void
swap_pointer(int *a, int *b)
{
    *b = *a + *b;
    *a = *b - *a;
    *b = *b - *a;
}

int
main(int argc, char **argv)
{
    int a = 0x55;
    int b = 0x11;
    /* use pointer */
    swap_pointer(&a, &b);
    printf("a:%x b:%x\n", a, b);
    /* use XOR */
    SWAP(a, b);
    printf("a:%x b:%x\n", a, b);
    return 0;
}

