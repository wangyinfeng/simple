/*====================================================================
 * Description: First time to know about the jagged array, write some
 *              code to know it better.
 * DATE: 2013/10/23
 * Modify:
 * Conclusion: Maybe jagged array is not used widely, but understand
 *             it make your know more about the array and pointer
===================================================================*/
/* include */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Macro definition */
#define TRUE            1
#define FALSE           0

/* Declare a jaggered array, the length of each dimension is
 * [1,2,3,0], assign value to it, and then print
 * the value out, and do realloc the 4th length to 10. */

#if 0
/* Approach A. */
int
main(int argc, char **argv)
{
    int jagged_length[] = {1,2,3,10};
    int dimensions = 4;
    int i, j;
    int (*(p[])) = {(int []){1},
                    (int []){2,3},
                    (int []){4,5,6},
                    (int []){}
    };
    p[3] = malloc(sizeof(int)*jagged_length[3]);
//    memset(p[3], 1, sizeof(int)*jagged_length[3]); /* memset, operation for BYTE */
    for(i=0; i<jagged_length[3]; i++){
        p[3][i] = 1;
    }
    for(j=0; j<dimensions; j++){
        for(i=0; i<jagged_length[j]; i++) {
            printf("p[%d][%d]: address:%p, value:%02d\n", j, i,&p[j][i], p[j][i]);
        }
    }
    
    return 0;
}
#endif
#if 0
/* Approach B. */
int
main(int argc, char **argv)
{
    int jagged_length[] = {1,2,3,10};
    int dimensions = 4;
    int i, j;
    int p1[] = {1};
    int p2[] = {2,3};
    int p3[] = {4,5,6};
    int p4[] = {};
    int *p[] = {p1,p2,p3,p4};
    p[3] = malloc(sizeof(int)*jagged_length[3]);
    for(i=0; i<jagged_length[3]; i++){
        p[3][i] = 1;
    }
    for(j=0; j<dimensions; j++){
        for(i=0; i<jagged_length[j]; i++) {
            printf("p[%d][%d]: address:%p, value:%02d\n", j, i,&p[j][i], p[j][i]);
        }
    }
    
    return 0;
}
#endif

#if 0
/* Approach C. */
int
main(int argc, char **argv)
{
    int jagged_length[] = {1,2,3,10};
    int dimensions = 4;
    int i, j;
    int p1[] = {1};
    int p2[] = {2,3};
    int p3[] = {4,5,6};
    int p4[] = {};
    int **p = (int *[]){p1,p2,p3,p4};
    p[3] = malloc(sizeof(int)*jagged_length[3]);
    for(i=0; i<jagged_length[3]; i++){
        *(p[3]+i) = 1;
    }
    p[1][1] = 8; 
    for(j=0; j<dimensions; j++){
        for(i=0; i<jagged_length[j]; i++) {
            printf("p[%d][%d]: address:%p, value:%02d\n", j, i,&p[j][i], p[j][i]);
        }
    }
    return 0;
}
#endif
/* Approach D. */
int
main(int argc, char **argv)
{
    int jagged_length[] = {1,2,3,10};
    int dimensions = 4;
    int i, j;
    int p1[] = {1};
    int p2[] = {2,3};
    int p3[] = {4,5,6};
    int p4[] = {};
    int (*p[])[] = {&p1,&p2,&p3,&p4};
    p[3] = malloc(sizeof(int)*jagged_length[3]);
    for(i=0; i<jagged_length[3]; i++){
        *(*p[3]+i) = 1;
    }
    *(*p[1]+1) = 8; 
    for(j=0; j<dimensions; j++){
        for(i=0; i<jagged_length[j]; i++) {
            printf("p[%d][%d]: address:%p, value:%02d\n", j, i,(*p[j]+i), *(*p[j]+i));
        }
    }
    return 0;
}
