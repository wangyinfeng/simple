/*====================================================================
 * Description: Have n persons arranged in a circle, every m-th man will
 * be exectued going around the circle until only ONE remains, find the
 * position where you should stand in order to be the last survior.
 * DATE: 2014/06/10
 * Modify:
 * Conclusion:
===================================================================*/
/* include */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/* Macro definition */
#define false           0
#define true            1

unsigned int 
josephus(unsigned int n, unsigned m)
{

}

/* input the n and m from command line, where n>1 */
int
main(int argc, char **argv)
{
    if (argc < 3) {
        fprintf(stderr, "incorrect parameters\n");
        exit(1);
    }
    unsigned int n,m,p;
    n = atoi(argv[1]);
    m = atoi(argv[2]);
    if ( (n<2) || (m<1) ) {
        fprintf(stderr, "invalid parameters\n");
        exit(1);
     }
     printf("[%d] mem stand in cycle, the [%d]th man will be exectued\n", 
         n, m);
    p = josephus(n, m);
    printf("stand at position [%d] will survior\n", p);

    return 0;
}

