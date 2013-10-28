/*====================================================================
 * Description: An interesting example of the sort() described
 *              at page 131. Practice the function pointer usage
 *              and string.
 * DATE: 2013/10/17
 * Modify: 2013/10/28
 * Conclusion: Please learn the sorting.
===================================================================*/
/* include */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Macro definition */
#define true            1
#define false           0

/* typedef not always define a new type */
typedef int (*fptrOperation)(const char*, const char*);

char* names[] = {"Bob", "Ted", "Carol", "Alice", "alice"};

int 
compare(const char* str1, const char* str2)
{
    return strcmp(str1, str2);
}

char *
str_to_lower(const char *str)
{
    char *temp = NULL;
    int i = 0;
    if(str) {
        temp = malloc(strlen(str)+1); /* mess the strlen and sizeof */ 
        for (i=0; i<strlen(str); i++)
            *(temp+i) = tolower(*(str+i));

        *(temp+i) = '\0';
    }
    return temp;
}

int 
compareIgnoreCase(const char* str1, const char* str2)
{
    int result;
    char *s1 = str_to_lower(str1);
    char *s2 = str_to_lower(str2);
    result = strcmp(s1, s2);
//    printf("s1 %s\n", s1);
//    printf("s2 %s\n", s2);
    free(s1);
    free(s2);
    return result;
}

/* The 1st parameter of the sort() is the string array wait
 * for sorting, the 2nd parameter is the number of string
 * in that array, the 3rd parameter is the operation, compare
 * with case sensitive or ignore case. And at last, print
 * the sort result */
void
sort(char *array[], int size, fptrOperation operation)
{
    int i, swap = true;
    while(swap == true) {
        swap = false;
        for (i=0; i< size -1; i++) {
            if (operation(array[i], array[i+1]) > 0){
                swap = true;
                char *temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
            }
        }
    }
}

void
displayNames(char *array[], int num)
{
    int i;
    for(i=0; i<num; i++) {
        printf("%s ", array[i]);
    }
    printf("\n");
}

int
main(int argc, char **argv)
{

    printf("Original sequence:\t\t\t");
    displayNames(names,5);

    sort(names,5,compare);
    printf("After sort with case sensitive:\t\t");
    displayNames(names,5);

    sort(names,5,compareIgnoreCase);
//    printf("%s tolower %s\n", names[0], str_to_lower(names[0]));
    printf("After sort without case sensitive:\t");
    displayNames(names,5);

    return 0;
}

