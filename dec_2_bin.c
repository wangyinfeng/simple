/*====================================================================
 *Description: Convert the decimal number to binary, store the binary 
 *              number in an array, low bit store in low index
 *DATE: 2015.8.11
 *Modify:
 *
===================================================================*/
#include <stdio.h>
#include <stdlib.h>

#define SWAP(a, b) (a)^=(b), (b)^=(a), (a)^=(b)

int main(int argc, char *argv[])
{
    int num = 0;
    char bin[32]={}, r_bin[32]={};
    int i = 0, width = 0;
    if(argc < 2) {
        printf("Please input the number\n");
        return 1;
    }
    num = atoi(argv[1]);
    do {
//      bin[i] = num&1 + '0'; //why not work?! - num&1 is a bool, the result is a bool
        bin[i] = num&1;
        bin[i] += '0';
        num >>= 1;
        i++;
    }while(num!=0);

    width = i;
    for (i=0; i<width/2; i++) {
        SWAP(bin[i], bin[width-i-1]);
    }

    bin[width] = '\0';
    printf("%s\n", bin);
    return 0;
}
