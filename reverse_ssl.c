/*====================================================================
 * Description: Since you seems know nothing about linked list...
 * One practice:
 * Given a linked list, we need to write a function that reverses the 
 * nodes of a linked list 'k' at a time and returns modified linked list.
 * The following are the constraints given:
 * - If the no. of nodes in a link list is not a multiple of k then 
 *   left-out nodes in the end should remain as it is
 * - You have to retain the memory address of the nodes without modifying 
 *   it i.e. you can't just interchange the values in the nodes
 * - Only constant memory is allowed
 * For example the linked list given is as follows:
 *  Linked List : 1->2->3->4->5->6->7->8->9->10->11->null
 *  For k = 2
 *  Return Value: 2->1->4->3->6->5->8->7->10->9->11->null
 *  For k = 3
 *  Return value: 3->2->1->6->5->4->9->8->7->10->11->null
 *
 * DATE: 2013/10/22
 * Modify: 2013/10/24
 * Conclusion: Know nothing about linked list! 
 *             Seems never use it and never know it.
 *             The root is about pointer operation and abstract
 *             imagenation, admit it, you are not an exterienced
 *             C programmer.
 *
===================================================================*/
/* include */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Macro definition */
#define true            1
#define false           0

/* First, implement the linked list initialize function,
 * provide a function to insert element to the tail of
 * the linked list, by recursion */
#define MAX_LIST_LEN    8

typedef struct Node_t {
    int     value;
    struct Node_t  *next;
}Node_t;

/* The input parameter of node must be the address of the pointer to the header,
 * so the parameter should declared as pointer to pointer of Node_t, so the
 * function is able to change the contant of that address, from NULL to some
 * new alloced space */
int
insert_ssl(Node_t **node, int value)
{
    if ((*node) == NULL) { /* first */
        (*node) = (Node_t *)malloc(sizeof(Node_t));
        (*node)->value = value;
        (*node)->next = NULL;
    }
    else {
        insert_ssl(&((*node)->next), value);
    }
}

/* print the linked list */
void
print_ssl(Node_t *node)
{
    int i;
    Node_t *walk = node;
    printf("Head->");
    if(node == NULL){
        printf("List is NULL\n");
        return;
    }

    do{
        printf("%d->", walk->value);
        walk = walk->next;
    }while(walk);
    printf("NULL\n");
}

/* http://crackinterviewtoday.wordpress.com/tag/linked-lists/ */
Node_t *
reverse_ssl(Node_t *node, int k)
{
    return NULL;
}


/* simply reverse the total linked list */
Node_t *
simple_reverse_ssl(Node_t *cur)
{
    if (cur == NULL) {
        printf("List is NULL\n");
        return NULL;
    }
    Node_t *prev = NULL;
    while (cur) {
        Node_t *temp = cur;
        cur = cur->next;
        temp->next = prev;
        prev = temp;
    }
    return prev;
}

int
main(int argc, char **argv)
{
    int i;
    int init_value[MAX_LIST_LEN] = {8,7,6,5,4,3,2,1};
    Node_t  *head = NULL;
    Node_t  *reversed = NULL;
    for(i=0; i<MAX_LIST_LEN; i++) {
        insert_ssl(&head, init_value[i]);
    }
    print_ssl(head);

    reversed = simple_reverse_ssl(head);
//    reverse_ssl(head, 8);
    print_ssl(reversed);
    return 0;
}

