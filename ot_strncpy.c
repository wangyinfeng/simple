/* my implement of strcpy
 * Test case:
 * 1. Null destination, Null source
 * 2. source is longer than destination
 * 3. source is the destination
 *
 * clib behavior:
 * 1. NULL destination/source, segmentation fault
 * 2. source is longer than destination, overlap
 * 3. no error
 *
 * Conclusion:
 * quite similar to the clib implement. 
 * try to implement the stcncpy()
 * */
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

char des[8];
char input[64];
char *
ot_strcpy(char *des, const char *src)
{
    int i=0;
    if (des == NULL) {
        printf("destination address is invalid\n");
        return des;
    }
    if (src == NULL){
        printf("source address is NULL, nothing to copy\n");
        return des;
    }
    /* why use the variable i? I think you are not familiar with
     * the ++/-- operations
     * */
    /*
    do {
        *(des+i) = *(src+i);
        i++;
    } while(*(src+i) != NULL);
    */
    do {
        *(des++) = *(src++);
    } while(*src != NULL);
    printf("%d character copyed\n", i);
    return des;
}

int 
/* Seems you never use the main parameters before 
 * Use the command line parameter to do test 
 */
main(int argc, char **argv)
{
	printf("\ninput the string to be copyed: ");
	fgets(input, 64, stdin);
	ot_strcpy(des, input);
	printf("string copyed: %s\n", des);
}

/* implement in std clib */
