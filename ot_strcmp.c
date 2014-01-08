/*====================================================================
 * Description: implement the strcmp
 * DATE: 2014/01/08
 * Modify:
 * Conclusion: After several changs, quite close to the std implement
===================================================================*/
/* include */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Macro definition */
#define false           0
#define true            1

char input[64];

/* misunderstand the return value, not limit to -1,0,1
 * but greater than 0, 0, less than 0 */
int ot_strcmp(const char *str1, const char *str2)
{
#if 0
    int i=0;
    for(;(*(str1+i) && *(str2+i));i++)
    {
        if (*(str1+i) > *(str2+i))
            return 1;
        else if(*(str1+i) < *(str2+i))
            return -1;
        else
            continue;
    }
    if (*(str1+i) > *(str2+i))
        return 1;
    else if (*(str1+i) < *(str2+i))
        return -1;
    else
        return 0;
#endif
#if 0
    for (;*str1++ && *str2++;)
    {
        if (*str1 == *str2)
            continue;
        else
            return (*str1 - *str2) > 0 ? 1 : -1;
    }
    if (*str1 == *str2)
        return 0;
    else
        return (*str1 - *str2) > 0 ? 1 : -1;
#endif 
#if 0 /* correct the return value */
    while(((*str1++ - *str2++) == 0) && *str1 && *str2);
    if (*str1 > *str2)
        return 1;
    else if(*str1 < *str2)
        return -1;
    else 
        return 0;
#endif
    while(((*str1++ - *str2++) == 0) && *str1 && *str2);
    return (*str1 - *str2);
}

int
main(int argc, char **argv)
{
    char *str1 = "Apple\n";
//    char *str1 = "";
    printf("input the string to compare:\n");
    fgets(input, 64, stdin);
    int r = ot_strcmp(str1, input);
//    int r = ot_strcmp("", "");
    printf("result %d\n",r);
    return 0;
}

/* clib implement */
int _strcmp(const char* s1, const char* s2)
{
    while(*s1 && (*s1==*s2))
        s1++,s2++;
    return *(const unsigned char*)s1-*(const unsigned char*)s2;
}

