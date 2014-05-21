/*====================================================================
 * Description: dump the specified memory, with various format
 * DATE: 2014/05/21
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

/* malloc a space, and dump it */

void
dump_by_byte(void *addr, int len)
{
    int i;
    if (addr == NULL) {
        perror("invalid address\n");
        return;
    }
    printf("Address:\t Data:\n");
    for (i=0; i<len; i++) {
        if ( i%16 == 0 ) {
            if (i != 0 )
                printf("\n");
            printf("%p:\t", addr+i);
        }
        printf("%02x ", *((char *)(addr+i)));    
    }
    printf("\n");
}

void
dump_by_word(void *addr, int len)
{
    int i;
    if (addr == NULL) {
        perror("invalid address\n");
        return;
    }
    printf("Address:\t Data:\n");
    for (i=0; i<len; ) {
        if ( i%16 == 0 ) {
            if (i != 0 )
                printf("\n");
            printf("%p:\t", addr+i);
        }
        printf("%08x ", *((int *)(addr+i)));    
        i+=4;
    }
    printf("\n");
}

void
int
main(int argc, char **argv)
{
    int length = 256;
    void *start = malloc(length);
    dump_by_byte(start, length);
    
    dump_by_word(start, length);

    return 0;
}

