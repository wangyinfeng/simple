#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct list{
    struct ListNode     *head;
    struct ListNode     *tail;
    struct ListNode     *current;
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
    struct ListNode *new = (struct ListNode *)malloc(sizeof(struct ListNode));
    new->val = data;
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
    struct ListNode *new = (struct ListNode *)malloc(sizeof(struct ListNode));
    new->val = data;
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

struct ListNode *
getNode(int data)
{
    L.current = L.head;
    while(L.current) {
        if (L.current->val == data) {
            return L.current;
        }
        else {
            L.current = L.current->next;
        }
    }
    return NULL;
}

int
delNode(struct ListNode *n)
{
    struct ListNode *prv = L.head;
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
            printf("%d->", l->current->val);
            l->current = l->current->next;
        } while(l->current);
        printf("NULL]\n");
    }
}

/* You may not modify the values in the list, only nodes itself can be changed. */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode* one;
    struct ListNode* two;
    struct ListNode* current = head;
    struct ListNode* real_head = NULL;
    if (head->next)
        real_head = head->next;
    /* swap the ->next */
    while (current->next) {
        one = current->next->next;
        two = current;
        current->next->next = current;
        current->next = one;
        current = one;
    }
    return real_head;
}

int 
main(void)
{
    int i;
    struct ListNode *the = NULL;
    init(&L);
    
    for (i=10; i<20; i++) {
        addTail(i);
    }
    print(&L);
    the = swapPairs(L.head);
    while (the) {
        printf("%d ", the->val);
        the = the->next;
    };
    printf("\n");
    //print(&L);

    return 0;
}

