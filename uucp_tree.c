/*====================================================================
 * Description: Implement the tree, binary tree... strange to me
 *              Also kind of linked list? with left and right two
 *              arms?
 * DATE: 2013/11/1
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

typedef struct _tree{
    void *data;
    struct _tree *left;
    struct _tree *right;
}Tree;

/* insert node to the tree, if the data is larger than the parent's
 * insert to the right leaf, if the data is smaller than the 
 * parent's, insert to the left leaf, if is euqal to the parent's
 * insert to the left leaf also. */
void
insert(Tree **root, void *data)
{
}

void displayTree(Tree *t)
{
}
int
main(int argc, char **argv)
{

    return 0;
}

