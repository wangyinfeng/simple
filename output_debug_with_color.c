//usr/bin/make -s "${0%.c}" && ./"${0%.c}" "$@"; s=$?; rm ./"${0%.c}"; exit $s
/* make will call default $CC to compile the file
 * ${0%.c} to get the filename without the extension
 * $@ to get all parameters
 * $? to get the exit code 
 *
 * Reference: 
 * https://news.ycombinator.com/item?id=9144467
 * https://github.com/ryanmjacobs/c
 * */
/*====================================================================
 * Description: Introduce a good way to output debug info with color.
 * Copy from http://maciejczyzewski.me/2015/02/21/better-debug-notices-in-c-using-macros.html
 * DATE: 2015/04/1
 * Modify:
 * Conclusion: Really useful, also depends on the console configure
===================================================================*/
/* include */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Debugger Marcos */
#define note(S, ...) fprintf(stderr,                                     \
          "\x1b[1m(%s:%d, %s)\x1b[0m\n  \x1b[1m\x1b[35mnote:\x1b[0m " S "\n",    \
          __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__)

#define warn(S, ...) fprintf(stderr,                                     \
          "\x1b[1m(%s:%d, %s)\x1b[0m\n  \x1b[1m\x1b[33mwarning:\x1b[0m " S "\n", \
          __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__)

#define errn(S, ...) do { fprintf(stderr,                                \
          "\x1b[1m(%s:%d, %s)\x1b[0m\n  \x1b[1m\x1b[31merror:\x1b[0m " S "\n",   \
          __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__); exit(1); } while (0) 

int
main(int argc, char **argv)
{
    note("this will be a hard error in the future");
    warn("function '%s' redefined as non-inline", "my_function");
    errn("no such file or directory");
    return 0;
}

