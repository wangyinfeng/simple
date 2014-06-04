/*====================================================================
 * Description: Seems you know nothing about sorting, basic algorithm,
 *              worth to do some practice
 *              Bubble sorting, the simplest sorting.
 *              1. Compare the adjacent elements, move the bigger to the tail;
 *              2. The remain un-sorting number --;
 *              3. One traversal decide one biggest element;
 *              4. Until all element be sorted.
 *
 * DATE: 2013/11/27
 * Modify: 2014/06/04 - read random number from file
 * TODO: Is it necessary to put the common function to a seprate file
 *       and use them by include the head file?
 * Conclusion:
===================================================================*/
/* include */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Macro definition */
#define true            1
#define false           0

#define SWAP(a, b)  (a^=b, b^=a, a^=b)
#define EOL                 '\n'
#define CHAR_RETURN         '\r'
#define RANDOM_STORE        "random.number"

#if defined STATICS
int num[] = {2,4,12,34,3,56,23,67,90,1,66,43};
#endif 

int comp_count;

int 
line_count(char* file) 
{
    FILE* fd;
    char ch;

    if ((fd = fopen(file, "r")) == NULL) {
        printf("Failed opening the file\n");
        exit(1);
    }

    unsigned int line_count = 0;
    while ( (ch = fgetc(fd)) != EOF)
        if (ch == EOL || ch == CHAR_RETURN)
            ++line_count;

    if (fd) {
        fclose(fd);
    }

    return line_count;
}

int
get_random_number_from_file(char *name, int num[])
{
    FILE* fp = NULL;
    char line[32];
    unsigned int i = 0;

    fp = fopen(name, "r");
    if (fp == NULL) {
        fprintf(stderr, "Fail to open file %s\n", name);
        exit(1);
    }   
    else {
        while(fgets(line, sizeof(line), fp) != NULL) {
            num[i] = atoi(line);
            i++;
        }
        fclose(fp);
    }   
    printf("\n");
    return 0;
}

void
print_num(int n[], int size)
{
    int i;
    for (i=0; i<size; i++){
        printf("%02d ", n[i]);
    }
    printf("\n");
}

void
sort_A(int n[], int size)
{
    int i = 0;
    int tmp;
    do {
        for (i=0; i<size-1; i++) {
            if (n[i] > n[i+1]) {
                tmp = n[i];
                n[i] = n[i+1];
                n[i+1] = tmp;
            }
            comp_count++;
        }
        size--;
    } while(size);
}

/* if no swap happened when traveral, means sort finished, quit
 * avoid unncessary walk */
void
sort_B(int n[], int size)
{
    int ok = true;
    int i;
    while (ok) {
        ok = false;
        for (i=0; i<size-1; i++) {
            if (n[i] > n[i+1]) {
                SWAP(n[i], n[i+1]);
                ok = true;
            }
            comp_count++;
        }
        size--;
    }
}

int
main(int argc, char **argv)
{
    int size;
#if defined STATICS
    size = sizeof(num)/sizeof(int);
    if (size < 2)
        printf("Element number less than 2, quit\n");
#elif defined DYNAMIC
    size = line_count(RANDOM_STORE);
    int *num = malloc(size*sizeof(int));
    get_random_number_from_file(RANDOM_STORE, num);
#else
    size = line_count(RANDOM_STORE);
    int num[size];
    get_random_number_from_file(RANDOM_STORE, num);
#endif

    printf("Original sequence:\n");
    print_num(num, size);
    
    if (argc != 2) {
        fprintf(stderr, "Please specified the sorting function\n");
        return 0;
    }
    if (*argv[1] == 'A') {
        sort_A(num, size);
        printf("Sorted sequence:\n");
        print_num(num, size);
        printf("compare count %d\n", comp_count);
    }
    else if (*argv[1] == 'B') {
        sort_B(num, size);
        printf("Sorted sequence:\n");
        print_num(num, size);
        printf("compare count %d\n", comp_count);
    }

    return 0;
}

