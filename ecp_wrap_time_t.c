/*====================================================================
 * Description: When the time_t will wrap
 * DATE: 2014/12/02
 * Modify:
 * Conclusion: 
 * - First time to know the year 2038 problem;
 * - Know the C did not have unsigned type at the beginning
===================================================================*/
/* include */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/* Macro definition */
#define false           0
#define true            1

int
main(int argc, char **argv)
{
    time_t time;
    /*How long the time_t is?
     * gcc -E to do preprocess the source file, can get the definiation of the time_t:
     * typedef __time_t time_t;
     * typedef long int __time_t;
     * So on my machine the time_t is signed long int*/
    printf("The size of time_t %d\n",sizeof(time)); /*long is 32 bits*/

    /*why the time_t is signed? unsigned can contain more.
     * It's because time_t is older than the epoch(1970), and at the beginning, C did not have unsigned type,
     * the unsigned type was introduced by K&R at 1978.
     * When extend the time_t to 64 bits, it's large enough.*/
    time = 0x7fffffff; 

    /*why need the &time instead of time?
     * I guess pass pointer is more efficient then value*/
    printf("wrap at local time \t%s", ctime(&time)); 
    printf("wrap at UTC itme \t%s", asctime(gmtime(&time))); /*gmtime() to get UTC time, instead of LOCAL time*/

    /*Well, how to solve the year 2038 problem, is it a serious problem?
     * short answer: there is no universal solution for this problem
     * - use unsigned int only delay the wrap time, and also lost the ability to represent the year before epoch
     * - use b4 bits time_t is the most commen solution case, but has compatibility issue also.*/
    
    return 0;
}

