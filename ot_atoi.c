/*====================================================================
 *Description: Someone said the atoi is simple, but not many coder
    can implement it correctly, so I'll take a try, and to see how
    much time and submit I needed to finish it.
 *DATE: 2013/09/28
 *Modify: - Read input from file, one line one string
 *
===================================================================*/
#include <stdio.h>
#include <string.h>

#define true            1
#define false           0
#define MAX_NUM_LEN     8
#define IS_PLUS(_c)         (((_c) == '+') ? true : false)
#define IS_MINUS(_c)        (((_c) == '-') ? true : false)
#define IS_NUM(_c)          (((_c) <= '9' && (_c) >= '0') ? true: false)
#define IS_SPACE(_c)        (((_c) == ' ') ? true : false)
#define CHAR_TO_INT(_c)     ((_c) - '0')

int
a2i(const char* str)
{
    char    sign=' ';
    int     i;
    int     integer=0;
    unsigned char   all_space=true;
    unsigned char   has_sign=false;
    int     str_size = strlen(str);
    for (i=0; i<str_size; i++)
    {
        if (IS_SPACE(*(str+i))) {
            if (all_space)
                continue;
            else
                break;
        }

        if (IS_PLUS(*(str+i))) {
            if (has_sign) {
                break;
            }
            else {
                sign='+';
                all_space=false;
                has_sign=true;
            }
        }
        else if (IS_MINUS(*(str+i))) {
            if (has_sign) {
                break;
            }
            else {
                sign='-';
                all_space=false;
                has_sign=true;
            }
        }
        else if (!IS_NUM(*(str+i)))
            break;
        else if (IS_NUM(*(str+i))) {
           all_space=false;
           has_sign=true;
           integer = integer * 10 ; 
           integer += (int)CHAR_TO_INT(*(str+i));
        }
        else
            printf("Unexpect char!\n");
    }
    if (sign == '-')
        return (~integer+1); /* how can I forget it? */
    else
        return integer;
}

int
main(void)
{
#if 0
    char str[MAX_NUM_LEN];
    printf("Please input the test number, support plus-minus integer:\n");
//    scanf("%8s", str);
    fgets(str, sizeof(str), stdin);
    printf("The number you want to show is: %d\n", a2i(str));
#endif

    static const char test_case[] = "ot_atoi.c.case";
    FILE *file = fopen (test_case, "r");
    if ( file != NULL ){
        char line [128];
        char limit_line [MAX_NUM_LEN];
        while ( fgets( line, sizeof(line), file ) != NULL ) /* read a line */
        {
            printf("get input string: ");
            fputs(line, stdout); /* write the line */
            memcpy(limit_line, line, MAX_NUM_LEN);
            printf("The number is: %d\n", a2i(limit_line));
        }
        fclose(file);
    }
    else
    {
        perror (test_case); /* why didn't the file open? */
    }

    return 0;
}

/* Compare to the GNU implemetation, my code sucks!
 */
long __cdecl atol(
        const char *nptr
        )
{
        int c;              /* current char */
        long total;         /* current total */
        int sign;           /* if '-', then negative, otherwise positive */

        /* skip whitespace */
        while ( isspace((int)(unsigned char)*nptr) )
            ++nptr;

        c = (int)(unsigned char)*nptr++;
        sign = c;           /* save sign indication */
        if (c == '-' || c == '+')
            c = (int)(unsigned char)*nptr++;    /* skip sign */

        total = 0;

        while (isdigit(c)) {
            total = 10 * total + (c - '0');     /* accumulate digit */
            c = (int)(unsigned char)*nptr++;    /* get next char */
        }

        if (sign == '-')
            return -total;
        else
            return total;   /* return result, negated if necessary */
}
