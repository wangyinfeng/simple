/*====================================================================
 * Description: Kind of classic program practice?
 *              print the fibonacci number
 * DATE: 2013/10/17
 * Modify: 2014/06/05 implement it.
 * Fn = Fn-1 + Fn-2 , n=1,2,3... are 1,1,2,3,5...
 * F0 = 0, F1=F2=1
 *
===================================================================*/
/* include */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Macro definition */
#define true            1
#define false           0
unsigned int Fn_1, Fn_2;

unsigned int
fibonacci(unsigned int n)
{
    unsigned int x;
    if (n > 2) {
        x = fibonacci(n-1) + fibonacci(n-2);
        return x;
    }
    else if (n == 2) {
        return 1;
    }
    else if (n == 1) {
        return 1;
    }
    else {
        printf("Invalid 'n'!\n");
    }
    return 0;
}

/* input the n, print the Fn,Fn-1,Fn-2.... */
int
main(int argc, char **argv)
{
    unsigned int n;
    
    if (argc < 2) {
        printf("Please input the 'n'\n");
        exit(1);
    }
    n = atoi(argv[1]);
    for (; n>0; n--) {
        printf("%d ", fibonacci(n));
    }
    printf("\n");
    return 0;
}

