/*====================================================================
 * Description: When the time_t will wrap
 * DATE: 2014/12/02
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

int
main(int argc, char **argv)
{
    time_t time;
    printf("The size of time_t %d\n",sizeof(time));
    time = 0x7fffffff; /*is 32 bits length? depends on the platform? what about on 64 bits machine?*/
    printf("wrap at %s\n", ctime(&time)); /*why need the &time instead of time?*/
    printf("wrap at %s\n", asctime(gmtime(&time))); /*gmtime() to get UTC time, instead of LOCAL time*/

    return 0;
}

