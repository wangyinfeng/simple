/*====================================================================
 * Description: Zero length array is a gnu extension.
 * DATE: 2014/04/25
 * Modify:
 * Conclusion:
 * ===================================================================*/
/* include */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/* Macro definition */
#define false           0
#define true            1

struct line{
    int len;
    char contents[0];
};

struct row{
    int len;
    char *contents;
};

struct other{
    int len;
    char contents[]; /* like contents[0], not take memory */
};

int
main(int argc, char **argv)
{
    int required_length = 32;
    struct line *the_line = (struct line*)malloc(sizeof(struct line) + required_length);
    the_line->len = required_length;
    memset(the_line->contents, 0x55, the_line->len);
    /* some actions... */
    free(the_line);
    printf("the length of the struct line is %d\n", sizeof(struct line));
    /* there two ways to implement variable length struct, 
     * using zero length is better because
     * 1. zero length array not take memory, sizeof(contents[0]) is 0
     * 2. have continue address space, faster, and improve cache hits 
     *    rate. Using zero length array, the contents just follow the
     *    length element; while using the pointer, the contents address
     *    is decide by the pointer, who knows where it is.
     * 3. easy to manage memory, when free(this_line), free everything,
     *    while use the pointer, free(this_row) not able to free the
     *    memory pointed by contents */

/* (gdb) p *the_line
$1 = {len = 32, contents = 0x601014 'U' <repeats 32 times>}
(gdb) p the_line
$2 = (struct line *) 0x601010
(gdb) x/50b 0x601010
0x601010:       32      0       0       0       85      85      85      85
0x601018:       85      85      85      85      85      85      85      85
0x601020:       85      85      85      85      85      85      85      85
0x601028:       85      85      85      85      85      85      85      85
0x601030:       85      85      85      85      0       0       0       0
0x601038:       -47     15      2       0       0       0       0       0
0x601040:       0       0
*/    

    /* C99 provide flexible array, write a contents[] */

    struct row *the_row = (struct row*)malloc(sizeof(struct row));
    the_row->len = required_length;
    the_row->contents = malloc(required_length*sizeof(char));
    /* some actions ...*/
    memset(the_row->contents, 0x55, the_row->len);
    free(the_row->contents);
    free(the_row);
    printf("the length of the struct row is %d\n", sizeof(struct row));
/*
(gdb) p the_row
$1 = (struct row *) 0x601040
(gdb) p the_row->contents
$2 = 0x601010 'U' <repeats 36 times>
(gdb) x/64b 0x601010 
0x601010:       85      85      85      85      85      85      85      85
0x601018:       85      85      85      85      85      85      85      85
0x601020:       85      85      85      85      85      85      85      85
0x601028:       85      85      85      85      85      85      85      85
0x601030:       85      85      85      85      0       0       0       0
0x601038:       33      0       0       0       0       0       0       0
0x601040:       32      0       0       0       0       0       0       0
0x601048:       16      16      96      0       0       0       0       0
Heap grow from bottom to top
*/

    printf("the length of the struct other is %d\n", sizeof(struct other));

    return 0;
}
