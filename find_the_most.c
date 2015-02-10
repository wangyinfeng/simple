/*====================================================================
 * Description: Give a string, such as "1abb55cciijjj", find the character which appears most time.
 * The 1st step is provide the static source string;
 * Then read a file, for example the source code itself;
 * Only analysis the alphabet, ignore case, not consider other characters.
 * Suppose to finish in ONE hour. ---- Almost spent 2 hours.
 * DATE: 2015/01/07 / implement at 2015/02/10
 * Modify:
 * Conclusion:
===================================================================*/
/* The basic idea I can get is set a arrray which the length is the number of alphabet(26),
 * each element refer the appear number of the specified character, and traver the string,
 * count the number of each element, then sort the array to get which one appear the most.
 * ---- Not smart idea, can be done within one loop.
 * */

/* include */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/* Macro definition */
#define false           0
#define true            1
#define IS_ALPHA(A)     ((A)>=65 && (A)<=90) || ((A>=97) && (A)<=122)
/*Security issue here, this macro changed the value of the A, if use the macro
 * more than once, the 'A' is not the 'A' any more*/
//#define INDEX_ALPHA(A)  (A)=(A)>90?(A)-'a':(A)-'A' 
#define INDEX_ALPHA(A)  (A)>90?(A)-'a':(A)-'A'
#define COUNT_NUMBER    27
#define OTHER_ITEM      COUNT_NUMBER-1

char list[] = {"\
    A process is a program (object code stored on some media) in the midst of execution.\
    Processes are, however, more than just the executing program code (often called the text\
    section in Unix).They also include a set of resources such as open files and pending signals,\
    internal kernel data, processor state, a memory address space with one or more memory\
    mappings, one or more threads of execution, and a data section containing global variables.\
    Processes, in effect, are the living result of running program code.The kernel needs to\
    manage all these details efficiently and transparently."};
int show_times[COUNT_NUMBER] = {0};

int
count(char list[])
{
    unsigned char a;
    unsigned int i;
    for (i=0; list[i] != '\0'; i++) {
        a = list[i];
        if (IS_ALPHA(a))
            show_times[INDEX_ALPHA(a)]++;
        else
            show_times[OTHER_ITEM]++;
    }
    return 0;
}

/*Two loops to find the largest item in array, inefficient*/
int
compare(int times[], char *alpha)
{
    int tmp;
    unsigned char i;
    //char i; /* -Wall will report such warning: array subscript has type 'char'
    //due to the compiler don't want you to specify a negative array index, so
    //need to explicit declare with unsigned */
    int copy[COUNT_NUMBER] = {0};
    memcpy(copy, times, COUNT_NUMBER*sizeof(int));
    
    /*bubble the largest to the top*/
    for (i=0; i<COUNT_NUMBER-2; i++) {
        if (copy[i]>copy[i+1]) {
            tmp = copy[i];
            copy[i] = copy[i+1];
            copy[i+1] = tmp;
        }
    }
    for (i=0; i<COUNT_NUMBER; i++) {
        if (times[i] == copy[COUNT_NUMBER-2]) {
            *alpha = i + 'A';
            return times[i];
        }
    }
    return 0;
}


/*Much clear here
 * Traver the string and record the target at the sametime, one loop
 * will finish everything. */
int
return_the_max(char list[], char *alpha)
{
    *alpha =' ';
    unsigned char a;
    int max = 0;
    unsigned int i;

    for (i=0; list[i] != '\0'; i++) {
        if (IS_ALPHA(list[i])) {
            a = list[i];
            if (++show_times[INDEX_ALPHA(a)] > max) {
                max = show_times[INDEX_ALPHA(a)];
                *alpha = list[i];
            }
        }
    }
    return max;
}


int
main(int argc, char **argv)
{
    int times = 0;
    char alpha = 0;
#ifdef APPROACH_A
    count(list);
    times = compare(show_times, &alpha);
#endif
    times = return_the_max(list, &alpha);
    if (IS_ALPHA(alpha))
        printf("The alpha '%c' appreas the most times(%d)\n", alpha, times);
    else
        printf("What's happened?\n");
    return 0;
}

