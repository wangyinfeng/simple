/*The practice about the linked list once more, begin at 14:30, to see how much time is needed to do the implementation 
  the functions include print/addhead/addtail/get/delete 
    coding done at 15:30 
    compile done at 15:35, first run no suprise except addTail() not work 
    addTail worked at 15:43, but the delete the head target failed 
    delete the head target done at 15:50 */
/* I can say I have master the singal linked list */

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

typedef struct list{
    node    *head;
    node    *tail;
    node    *current;
}list;

list L;

void
init(list *l)
{
    l->head = l->tail = l-> current = NULL;
}

int
addHead(int data)
{
    node *new = (node *)malloc(sizeof(node));
    new->data = data;
    if (L.head == NULL) {
    /*the first element*/
        L.head = new;
        L.head->next = NULL;
        L.tail = L.current = L.head;
    }
    else {
        new->next = L.head;
        L.head = new;
        L.current = L.head;
    }
    return 0;
}

int
addTail(int data)
{
    node *new = (node *)malloc(sizeof(node));
    new->data = data;
    if (L.tail == NULL) {
    /*the first element*/
        new->next = NULL;
        L.tail = new;
        L.head = L.current = L.tail;
    }
    else {
        new->next = NULL;
        L.tail->next = new;
        L.tail = new;
        L.current = L.tail;
    }
    return 0;
}

node *
getNode(int data)
{
    L.current = L.head;
    while(L.current) {
        if (L.current->data == data) {
            return L.current;
        }
        else {
            L.current = L.current->next;
        }
    }
    return NULL;
}

int
delNode(node *n)
{
    node *prv = L.head;
    if (n == NULL) {
        printf("Invalid node.\n");
        return 1;
    }
    /*if the target is the head...*/
    if (prv == n) {
        L.head = prv->next;
        free(n);
        return 0;
    }
    else {
        while (prv->next) {
            if (prv->next == n) {
                prv->next = n->next;
                free(n);
                return 0;
            }
            else {
                prv = prv->next;
            }
        }
    }
    return 1;
}

void
print(list *l)
{
    if (l == NULL) {
        printf("Invalide list.\n");
        return;
    }

    if (l->head == NULL) {
        printf("Empty list.\n");
        return;
    }
    else {
        l->current = l->head;
        printf("[");
        do {
            printf("%d->", l->current->data);
            l->current = l->current->next;
        } while(l->current);
        printf("NULL]\n");
    }
}

int 
main(void)
{
    int i, n;
    node *the = NULL;
    init(&L);
    for (i=0; i<10; i++) {
        addHead(i);
    }
    print(&L);
    
    for (i=10; i<20; i++) {
        addTail(i);
    }
    print(&L);

    for (n=0; n<20; n++) {
        the = getNode(n);
        if (the) {
            printf ("Find the node contain the data %d at address %p\n", n, the);
            delNode(the);
            printf ("The new list after delete the found item is:");
            print(&L);
        }
        else {
            printf ("The data %d not exist. The entire list is:", n);
            print(&L);
        }
    }

    return 0;
}
