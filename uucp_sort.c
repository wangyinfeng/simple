/*====================================================================
 * Description: An interesting example of the sort() described
 *              at page 131. Practice the function pointer usage
 *              and string.
 * DATE: 2013/10/17
 * Modify:
 *
===================================================================*/
/* include */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Macro definition */
#define true            1
#define false           0

char* names[] = {"Bob", "Ted", "Carol", "Alice", "alice"};

int compare(const char* str1, const char* str2)
{
}

int compareIgnoreCase(const char* str1, const char* str2)
{
}

/* The 1st parameter of the sort() is the string array wait
 * for sorting, the 2nd parameter is the number of string
 * in that array, the 3rd parameter is the operation, compare
 * with case sensitive or ignore case. And at last, print
 * the sort result */
void
sort(char *array[], int size, fptrOperation operation)
{

}

int
main(int argc, char **argv)
{

//sort(names,5,compare);
//displayNames(names,5);
    return 0;
}

