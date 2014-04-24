/*====================================================================
 * Description: Practice the quiz about integer, know some detail about
 * integer overflow.
 * The link for the practice is http://blog.regehr.org/archives/721,
 * worth to do the test.
 * DATE: 2014/04/24
 * Modify:
 * Conclusion:
===================================================================*/
/* include */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/* Macro definition */
#define false           0
#define true            1

int
main(int argc, char **argv)
{
/* What does the expression 1U > -1 evaluate to? */
    /* when compare unsigned int and int, the unsigned int win, the operand
     * will promote to unsigned, the comparison is actually between
     * 1 and UNIT_MAX */
    /* avoid mixing signed and unsigned values in the same expression. */

/* What does the expression (unsigned short)1 > -1 evaluate to? */
    /* C "promotes" both operands to arithmetic operators to int type before 
     * performing the operation.  */

/* What does the expression SCHAR_MAX == CHAR_MAX evaluate to? */    
    /* The signedness of the char type is implementation-defined. 
     * ABIs for x86 and x86-64 tend to specify that char is signed */

/* What does the expression INT_MAX + 1 evaluate to? */
    /* Overflowing a signed integer is an undefined behavior. 
     * But overflowing a unsigned integer is guaranteed (UINT_MAX+1 == 0)*/

/* What does the expression -INT_MIN evaluate to? */
    /* Undefined */

/* Assume x has type int. Is the expression x<<0... */
    /* defined for some values of x */
    int i = -1;
    i = i<<0;
    printf("%d\n", i);
    /* a negative value cannot be left-shifted even by zero bit positions.
     * ? Not understand
     * understandable x << 1 is defined for some values of x, because
     * if x=INT_MAX, shiftting a 1 into the sign bit is an undefined
     * behavior. */
    /* I believe the compilers have defined behavoir for handding such
     * scenario, reading the manual can get answer for specific compiler */

/* Assume x has type int. Is the expression x<<32... */
    /* Shifting (in either direction) by an amount equalling or exceeding 
     * the bitwidth of the promoted operand is an error in C99. - got warning
     * on my computer*/
    /* "unsigned" can be legally shifted by an amount that is non-negative 
     * and also less than the width of the unsigned type. */

/* Assume x has type short. Is the expression x<<29... */
    /* defined for some value */
    /* Operands to shift operators are promoted before the shift executes.  */
    /* ? Not understand. the short will promote to int before do the operation? */

/* Assume x has type unsigned short. Is the expression x<<31... */    
    /* This one was just to make sure you've been paying attention. Since unsigned short is promoted to int, it is illegal to shift a 1 bit into or past the sign bit. If we shifted the value by 15 or fewer positions, the result would be defined for all values that can be stored in an unsigned short. */
    /* defined for some value */
    /* ? Not understand */
    return 0;
}

