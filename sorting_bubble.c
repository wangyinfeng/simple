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
 * Modify:
 * TODO:
 *        Input random number from file, and output the number to console.
 *        Should have more than one approach.
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

int num[] = {2,4,12,34,3,56,23,67,90,1,66,43};
int comp_count;

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
    size = sizeof(num)/sizeof(int);
    if (size < 2)
        printf("Element number less than 2, quit\n");

    printf("Original sequence:\n");
    print_num(num, size);
    
    if (argc != 2)
        return 0;
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

