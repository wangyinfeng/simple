/*====================================================================
 * Description: Implement the queue, according to the function 
 *              declaration in the book
 *              simply is the linked list again.
 * DATE: 2013/10/31
 * Modify:
 * Conclusion: It's simple if you manage the linked list. So the liked
 *             list is very important/useful.
===================================================================*/
/* include */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Macro definition */
#define true            1
#define false           0

/* Use linked list, enqueue is add a node to the head, and dequeue is
 * remove a node from it's tail */
typedef struct _node{
    int data;
    struct _node *next;
}Node;

typedef struct _linkedlist {
    Node *head;
    Node *current;
    Node *tail;
    int  num;
}LinkedList;

typedef LinkedList Queue;

void
initializeQueue(Queue *q)
{
    q->head = NULL;
    q->current = NULL;
    q->tail = NULL;
    q->num = 0;
}

/* add new node to the head of the queue -- the head of the linked list */
void 
enqueue(Queue *q, int i)
{
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = i;
    if (q->head == NULL) { /* empty */
        temp->next = NULL;
        q->tail = temp;
        q->num = 1;
    }
    else {
        temp->next = q->head;
        (q->num)++;
    }
    q->head = temp;
}

/* get data from the tail of the queue, and then remove the tail */
int 
dequeue(Queue *q)
{
    int v;
    if (q->head == NULL) {
        printf("empty queue\n");
        return 0;
    }
    q->current = q->head;
    if (q->head == q->tail) { /* one node */
        v = q->head->data;
        q->head = NULL;
        q->tail = NULL;
        free(q->current);
        q->current = NULL;
        q->num--;
        return v;
    }
    else {
        while (q->current->next != q->tail) {
            q->current = q->current->next;
        }
        v = q->tail->data;
        q->tail = q->current;
        free(q->current->next);
        q->current->next = NULL;
        q->num--;
        return v;
    }
}

void
displayQueue(Queue *q)
{
    if (q->num == 0 || q->head == NULL){
        printf("Queue is empty\n");
        return;
    }
        
    int i;
    q->current = q->head;
    printf("->");
    for (i=0; i<q->num; i++) {
        printf("%d->", q->current->data);
        q->current = q->current->next;
    }
    printf("\n");
}

int
main(int argc, char **argv)
{
    int i;
    int a;
    Queue Q;
    initializeQueue(&Q);
    for (i=0; i<5; i++){
        enqueue(&Q, i);
    }
    displayQueue(&Q);
#if 1
    for (i=0; i<5; i++) {
        a = dequeue(&Q);
        printf("dequeue %d\n", a);
    }
#endif 
    return 0;
}

