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
 * Description: A trick to run the c source file as script.
 * 'chmod +x example.c', then run as 'sh example.c' or './example.c'
 * The magic is the line 1 of the file, exaplain it and understand it.
 * DATE: 2015/03/05
 * Modify:
 * Conclusion: It's useful for single file, no need to compile the file
 * then run the output binary then maybe need to delete the binary.
===================================================================*/
/* include */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int
main(int argc, char **argv)
{
    printf("Hello!\n");
    return 0;
}

