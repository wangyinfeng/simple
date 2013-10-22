/*====================================================================
 * Description: Since you seems know nothing about linked list...
 * One practice:
 * Given a linked list, we need to write a function that reverses the 
 * nodes of a linked list 'k' at a time and returns modified linked list.
 * The following are the constraints given:
 * - If the no. of nodes in a link list is not a multiple of k then 
 *   left-out nodes in the end should remain as it is
 * - You have to retain the memory address of the nodes without modifying 
 *   it i.e. you can¡¯t just interchange the values in the nodes
 * - Only constant memory is allowed
 * For example the linked list given is as follows:
 *  Linked List : 1->2->3->4->5->6->7->8->9->10->11 -> null
 *  For k = 2
 *  Return Value: 2->1->4->3->6->5->8->7->10->9->11 ->null
 *  For k = 3
 *  Return value: 3->2->1->6->5->4->9->8->7->10->11 -> null
 *
 * DATE: 2013/10/22
 * Modify:
 * Conclusion:
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

typedef struct Node_s {
    int value;
    Node_t *next;
}Node_t;

int
insert_ssl(Node_t **node, int value)
{
    Node_t *temp;
    if (node == NULL) {
        temp = (Node_t *)malloc(sizeof(Node_t));
        temp->value = value;
        temp->next = NULL;
        node->next = temp;
    }
    else {
        insert_ssl(node, value);
    }
}

int
main(int argc, char **argv)
{
    int init_value[MAX_LIST_LEN] = {8,7,6,5,4,3,2,1};
    return 0;
}

