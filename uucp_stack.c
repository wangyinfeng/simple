/*====================================================================
 * Description: Implement the stack (FILO)
 *      Normally the samething as linked list, push data to the
 *      head, and pull data from head.
 * DATE: 2013/10/31
 * Modify:
 * Conclusion: More simpler than the queue, no need to travel the
 *             entire linked list.
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
    struct _node *next;
}Node;

typedef struct _linkedlist {
    Node *head;
    Node *current;
    Node *tail;
    int num;
}LinkedList;

typedef LinkedList Stack;

void
initStack(Stack *s)
{
    s->head = NULL;
    s->tail = NULL;
    s->current = NULL;
    s->num = 0;
}

/* push data to the head of the stack */
void
push(Stack *s, int i)
{
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = i;
    temp->next = s->head;
    if (s->head == NULL) { /* empty, new */
        s->tail = temp;
    }
    s->head = temp;
    s->num ++;
}

/* pop data from the head of the stack */
int
pop(Stack *s)
{
    int r = 0;
    if (s->head == NULL) {
        printf("empty stack\n");
        return 0;
    }
    if (s->head == s->tail) {
        r = s->head->data;
        free(s->head);
        initStack(s);
    }
    else {
        s->current = s->head;
        r = s->head->data;
        s->head = s->head->next;
        free(s->current);
        s->num --;
    }
    return r;
}

void
displayStack(Stack *s)
{
    int i;
    if (s->head == NULL) { /* empty */
        printf("empty stack\n");
    }
    s->current = s->head;
    printf("->");
    while(s->current) {
        printf("%d->", s->current->data);
        s->current = s->current->next;
    }
    printf("\n");
}

int
main(int argc, char **argv)
{
    Stack S;
    int i;
    int d;

    initStack(&S);
    for(i=0; i<5; i++) {
        push(&S, i);
    }
    displayStack(&S);

    for(i=0; i<5; i++) {
        d = pop(&S);
        printf("pop %d\n", d);
    }

    return 0;
}

