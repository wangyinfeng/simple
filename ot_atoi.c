/*====================================================================
 *Description: Someone said the atoi is simple, but not many coder
    can implement it correctly, so I'll take a try, and to see how
    much time and submit I needed to finish it.
 *DATE: 2013/09/28
 *Modify:
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
           integer = integer * 10 ; 
           integer += (int)CHAR_TO_INT(*(str+i));
        }
        else
            printf("Unexpect char!\n");
    }
    if (sign == '-')
        return (~integer+1);
    else
        return integer;
}

int
main(void)
{
    char str[MAX_NUM_LEN];
    printf("Please input the test number, support plus-minus integer:\n");
    scanf("%s", str);
    printf("The number you want to show is: %d\n", a2i(str));

    return 0;
}


