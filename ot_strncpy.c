/* my implement of strncpy
 * Test case:
 * 1. Null destination, Null source
 * 2. n is longer than the destination size
 * 3. n is ZERO
 *
 * clib behavior:
 * 1. NULL destination/source, segmentation fault
 * 2. n is longer than destination, not check; but will stop
 *    when source is to NULL
 * 3. nothing copy
 *
 * Conclusion:
 *  quite similar to the clib implementation. 
 * */
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

char des[8];
char input[64];
char *
ot_strncpy(char *des, const char *src, size_t n)
{
    int i=0;
    if (des == NULL) {
        printf("Segmentation fault: destination address is invalid\n");
        return des;
    }
    if (src == NULL){
        printf("Segmentation fault: source address is NULL, nothing to copy\n");
        return des;
    }
    /* there is no way to protect the n>destination size? cannot get the destination */

    while(i<n && ((*des++) = *(src++)))
    {
        i++;
    }
//    while(*(des++) = *(src++), (++i < n)); /* if n is ZERO..., this approach at least copy one char */
    printf("%d character copyed\n", i);
    return des;
}

int 
main(int argc, char **argv)
{
//	printf("\ninput the string and the length to be copyed: ");
//	fgets(input, 64, stdin);

    int len = 0;
    char *src = NULL;
    if (argc > 1) {
        len = atoi(argv[2]);
        src = argv[1];
    }
    else {
        printf("Please input the string and length, divide by the space\n");
        return 0;
    }

	ot_strncpy(des, src, len);
	printf("string copyed: %s, length : %d\n", des, len);

    return 0;
}

/* implement in std clib */
/* will stop when source reach NULL? */
char *
_strncpy(to, from, len)
	char *to;
	const char *from;
	int len;
{
	char *save = to;

	for (; len-- && (*to = *from); ++from, ++to);
	return(save);
}

