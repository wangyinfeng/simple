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
main(void)
{
    char test[32] = " abc ";
    ot_strcpy(des, test);
    printf("string copyed: %s\n", des);
    char test1[32] = " 123 ";
    ot_strcpy(des, test1);
    printf("string copyed: %s\n", des);
    while (1) {
        printf("\ninput the string to be copyed: ");
        /* should avoid to use scanf(), buffer overflow may happen
         * for such function. 
         * And scanf() is stand for "scan formatted", cannot accept
         * SPACE input, or some control character input, unless
         * use scanf("%10[0-9a-zA-Z ]s", str); 
         * use scanf is kind of junior programmer's behavior,
         * don't use it any more.
         * */
//        scanf("%s", input);
        fgets(input, 64, stdin);
        ot_strcpy(des, input);
        printf("string copyed: %s\n", des);
    }
}

/* implement in std clib */
#ifdef _NC_RESTRICT
char *strcpy(char *restrict dest, const char *restrict src)
#else
char *strcpy(char *dest, const char* src)
#endif
{
    char *ret = dest;
    while (*dest++ = *src++)
        ;
    return ret;
}


