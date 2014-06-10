/*====================================================================
 * Description: Have n persons arranged in a circle, every m-th man will
 * be exectued going around the circle until only ONE remains, find the
 * position where you should stand in order to be the last survior.
 * DATE: 2014/06/10
 * Modify:
 * Conclusion:
===================================================================*/
/* include */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/* Macro definition */
#define false           0
#define true            1

/* Another chance to test your understanding about linked list */
typedef struct node {
    struct node *next;
    unsigned int id;
}NODE;

typedef struct ll {
    NODE *header;
    NODE *tail;
    NODE *current;
    unsigned int count;
}LL;
LL poor_men;

/* create cycle linked list */
void
init_josephus(unsigned int n)
{
    unsigned int i;
    for (i=1; i<=n; i++) {
        NODE *temp=malloc(sizeof(NODE));
        if(i == n) { /* the last one */
            temp->next = poor_men.header;
        }
        else {
            temp->next = NULL;
        }
        temp->id = i;
        if (i == 1) {
            poor_men.header = temp;
        }
        else {
            poor_men.tail->next = temp;
        }
        poor_men.tail = poor_men.current = temp;
    }
    poor_men.count = n;
}
/* print linked list */
void
print_josephus(void)
{
    NODE *cur = poor_men.header;
    if (cur == NULL) {
        fprintf(stderr, "empty list\n");
        exit(1);
    }
    
    do {
        printf("[%d]->", cur->id);
        cur = cur->next;
        if (cur == NULL) {
            printf("Not cycle linked list?\n");
            exit(1);
        }
            
    } while (cur != poor_men.header);
    printf("[[%d]]", cur->id);
    printf("\n");
}
/* linked list delete */
void
execute_the_one(unsigned int m)
{
    NODE *previous;
    NODE *the_one;
    unsigned int j = 0;
    do {
        previous = poor_men.current;
        poor_men.current = poor_men.current->next;
        j++;
    } while(j < m);
    the_one = previous->next;
//    free(the_one);
    previous->next = poor_men.current->next;
    printf("Execute [%d] ", poor_men.current->id);
    printf("The remains are:");
    print_josephus();
}

unsigned int 
josephus(unsigned int n, unsigned m)
{
    unsigned int i;
    init_josephus(n);
    print_josephus();
    for (i=n; i>0; i--) {
        execute_the_one(m);
    }
    return poor_men.current->id;
}

/* input the n and m from command line, where n>1 */
int
main(int argc, char **argv)
{
    if (argc < 3) {
        fprintf(stderr, "incorrect parameters\n");
        exit(1);
    }
    unsigned int n,m,p;
    n = atoi(argv[1]);
    m = atoi(argv[2]);
    if ( (n<2) || (m<1) ) {
        fprintf(stderr, "invalid parameters\n");
        exit(1);
     }
     printf("[%d] mem stand in cycle, the [%d]th man will be exectued\n", 
         n, m);
    p = josephus(n, m);
    printf("stand at position [%d] will survior\n", p);

    return 0;
}

