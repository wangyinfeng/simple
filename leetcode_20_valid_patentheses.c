/* Before do the coding, think more, do not try to solve it without brain */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/* make stack to store the left parathese */
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

bool isValid(char* s) {
#define FALSE   0
#define TRUE    1
#define L_CURVE 1
#define L_SQUARE 2
#define L_BRACE 3

    Stack left;
    int next;
    initStack(&left);

    int len, i;
    if (s == NULL)
        return FALSE;

    len = strlen(s);
    if (len == 0) return TRUE;
    for (i=0; i<len; i++){
        switch (s[i]){
            case '(': push(&left, L_CURVE); break;
            case ')': 
                      next = pop(&left);
                      if (next != L_CURVE)
                          return FALSE;
                      break;
            case '[': push(&left, L_SQUARE); break;
            case ']': 
                      next = pop(&left);
                      if (next != L_SQUARE)
                          return FALSE;
                      break;
            case '{': push(&left, L_BRACE); break;
            case '}': 
                      next = pop(&left);
                      if (next != L_BRACE)
                          return FALSE;
                      break;
            default:
                break;
        }
    }
    if (left.head == NULL)
        return TRUE;
    else
        return FALSE;
}

int main(int argc, char ** argv)
{
    char *s = "([)]{}";
    //char *s = "[([]])";
    //char *s = "((())[{()}])";
    if (! isValid(s)) 
        printf("Invalid\n");
    else
        printf("Valid\n");

    return 0;
}
