/*====================================================================
 * Description: Implement the stack (FILO)
 *		Normally the samething as linked list, push data to the
 *		head, and pull data from head.
 * DATE: 2013/10/31
 * Modify:
 * Conclusion:
===================================================================*/
/* include */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Macro definition */
#define true            1
#define false           0

typedef struct _node{
    int data;
    struct _node node;
}Node;

typedef struct _linkedlist {
    Node *head;
    Node *current;
    Node *tail;
    int num;
}LinkedList;

typedef Stack LinkedList;

void
push(Stack *S) 
{
}

int
pop(Stack *S)
{
}

void
displayStack(Stack *S)
{
}

int
main(int argc, char **argv)
{

    return 0;
}

