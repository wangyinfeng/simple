/*====================================================================
 * Description: implement the printf
 *              to see after read the article about how to implement, am
 *              I able to 'redo' in 30 minutes?
 * DATE: 2014/11/06
 * Modify:
 * Conclusion: The usage about the varargs
===================================================================*/
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
extern char *  itoa ( int value, char * str, int base );

int
my_print(const char *fmt, ...) 
{
    int i, n;
    char a;
    char *p, *s;
    char format[32];

    va_list argp;
    va_start(argp, fmt);
    p = fmt; //warning here
    while(*p != '\0') {
        if (*p == '%') {
            p++;
            switch (*p) {
                case 'c':
                    i = va_arg(argp, int);
                    putchar(i);
                    n++;
                    break;
                case 'd':
                    i = va_arg(argp, int);
                    putchar(i);
                    n++;
                    break;
                case 's':
                    s = va_arg(argp, char *);     
                    fputs(s, stdout);
                    n++;
                    break;
                default:
                    putchar(*p);
                    n++;
                    break;
            }
        }
        else {
            putchar(*p);
            n++;
        }
        p++;
    }
    va_end(argp);
    return n;
}

int
main(void)
{
    int n;
    n = my_print("Test for the print function\n\t"
            "character %c\n\t"
            "integer %d\n\t"
            "string %s\n\t", 'a', 5, "Hello");
    /*integer print not correct*/

    printf("%d characters have printed\n", n);
}

