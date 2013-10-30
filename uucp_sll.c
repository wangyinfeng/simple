/*====================================================================
 * Description: Pointer and structure is mostly about data structure
 *              such as the linked list, stack, queue...
 *              Implement the example of the chapter, then compare
 *              your solution with the book:
 *              void initializeList(LinkedList*) Initializes the linked list
 *              void addHead(LinkedList*, void*) Adds data to the linked list's head
 *              void addTail(LinkedList*, void*) Adds data to the linked list's tail
 *              void delete(LinkedList*, Node*) Removes a node from the linked list
 *              Node *getNode(LinkedList*, COMPARE, void*) Returns a pointer to the 
 *              node containing a specific data item
 *              void displayLinkedList(LinkedList*, DISPLAY) Displays the linked list
 * DATE: 2013/10/30
 * Modify:
 * Conclusion: Normally, it works, after spent half a day. 
 *             Find more practice about linked list, to have full understand
 *             about the pointer.
===================================================================*/
/* include */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Macro definition */
#define true            1
#define false           0


typedef struct _node {
    int data;
    struct _node *next;
} Node;

typedef struct _linkedList {
    Node *head;
    Node *tail;
    Node *current;
} LinkedList;

typedef void (*link_oper)(LinkedList*, int);

/* Initializes the linked list */
void 
initializeList(LinkedList* list)
{
    list->head = NULL;
    list->tail = NULL;
    list->current = NULL;
} 

/* Adds data to the linked list's head */
/* Try not use the pointer to pointer... */
void 
addHead(LinkedList* list, int data) 
{
#if 1
    Node *temp = (Node*)malloc(sizeof(Node));
    Node *head = list->head;
    /* The issue about use variable head is when assign new value to
     * the head, only the head value be changed, the link->head value
     * not changed. because head contain the same value of link->head,
     * not contain the address of link->head, so simply not able to
     * update link->head value via the head. Unless assign the address
     * of link->head to the head, then dereference the head to update
     * that address's value */
/* [a]->[b]->[c]
 *  1    2    3   address of the linked list
 *
 *  [head][current][tail] (1,1,3)
 *    10     14      18   address of the list
 *
 *  [head]
 *    20                address of the head
 *
 *  [temp]
 *    30  
 *  
 *  [head] (1)
 *    20            head = list->head
 *
 *  head = temp 
 *  [head] (30)     
 *    20            !!! the link->head value not changed, the data in address[10] still be 1
 * 
 *  declare head as Node** head
 *  head = &(list->head)
 *  [head]   [*head]  [*(*head)]
 *    40        10        1
 *  *head = temp
 *  [*head] (30)  
 *    10            Here is really updated the date in address [10]
 * */    
//    printf("head %p\n", head);
//    Node *tail = list->tail;
    temp->data = data;
//    temp->next = head;
    if (list->head == NULL) { /* empty, create one */
        temp->next = NULL;
        list->tail = temp;
    }
    else {
        temp->next = list->head;
    }
    list->head = temp;
#endif
#if 0
    Node *node = (Node*) malloc(sizeof(Node));
    node->data = data;
    if (list->head == NULL) {
        list->tail = node;
        node->next = NULL;
    } else {
        node->next = list->head;
    }
    list->head = node;
#endif
}
#if 0
void 
addHead(LinkedList* list, int data) 
{
    Node *temp = (Node*)malloc(sizeof(Node));
    Node **head = &(list->head);
    Node **tail = &(list->tail);
    temp->data = data;
    temp->next = *head;
    if (*head == NULL) { /* empty, create one */
        *head = temp;
        *tail = temp;
    }
    else {
        *head = temp;
    }
}
#endif
/* Adds data to the linked list's tail */
void 
addTail(LinkedList* list, int data) 
{
    Node *temp = (Node*)malloc(sizeof(Node));
//    printf("%d:%p\n", data, temp);
    temp->data = data;
    temp->next = NULL;
    if (list->tail == NULL) {
        list->head = temp;
    }
    else {
        list->tail->next = temp; /* Don't know can be use as this! */
    }
    list->tail = temp;
#if 0
    Node **tail = &(list->tail);
//    Node *current = list->current; /* the list->current is used to travel the list */
    if (*tail == NULL) { /* empty, create new */
        *tail = temp;
        list->head = *tail;
    }
    else {
        (*tail)->next = temp;
        *tail = temp;
//        current->next = *tail;
    }
//    list->current = *tail;
    list->tail = *tail;
#endif
}

void
add_node(link_oper oper, LinkedList* list, int i)
{
    oper(list, i);
}

/* Removes a node from the linked list */
void 
deleteNode(LinkedList* list, Node* node) 
{
    if (node == NULL) {
        printf("Delete Null?\n");
        return;
    }
    if (node == list->head) {
        /* !Not consider only one node exist */
        if (list->head->next == NULL){
            list->head = NULL;
            list->tail = NULL;
        }
        else {
            list->head = node->next;
        }
    }
    else {
        list->current = list->head;
        Node **temp = &(list->current);
        while ((*temp)->next != node) { /* find the previous one */
            (*temp) = (*temp)->next;
        }
        (*temp)->next = node->next;
    }
    free(node);
}

/* Returns a pointer to the node containing a specific data item */
Node* 
getNode(LinkedList* list, int data) 
{
    Node *node = list->head;
    while(node) {
        if (node->data == data)
            break;
        else
            node = node->next;
    }
    if (node == list->tail)
        return NULL;
    else
        return node;
}

/* Displays the linked list */
void 
displayLinkedList(LinkedList* list) 
{
    Node *current = list->head;
    if(current)
        printf("H[");
    /* Not consider current is NULL */
    while(current){
        printf("%d->", current->data);
        current = current->next;
    }
    printf("\b\b]T\n");
}

int
main(int argc, char **argv)
{
    LinkedList  list;
    Node *node;
    int i, d;
    d = 3;
    initializeList(&list);

    add_node(addHead, &list, 111);
    add_node(addHead, &list, 110);
    add_node(addTail, &list, 0);
    displayLinkedList(&list);

    for(i=0; i<5; i++) {
//        addTail(&list, i);
        add_node(addTail, &list, i);
    }
    displayLinkedList(&list);

//    addHead(&list, i*10);
    add_node(addHead, &list, i*10);
    displayLinkedList(&list);
    
//    addTail(&list, i*100);
    add_node(addTail, &list, i*100);
    displayLinkedList(&list);

    node = getNode(&list, d);
    if (node)
        printf("get node %p contain data %d\n", node, d);
    else
        printf("the data %d not contain in the list\n", d);

    deleteNode(&list, node);
    displayLinkedList(&list);

    return 0;
}

