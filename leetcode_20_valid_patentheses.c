#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define FALSE   0
#define TRUE    1

bool isValid(char* s) {
    int curves = 0, square = 0, brace = 0, len, i;
    if (s == NULL)
        return FALSE;

    len = strlen(s);
    if (len == 0) return TRUE;
    for (i=0; i<len; i++){
        switch (s[i]){
            case '(': curves++; break;
            case ')': curves--; break;
            case '[': square++; break;
            case ']': square--; break;
            case '{': brace++; break;
            case '}': brace--; break;
            default:
                break;          
        }
    }
    if (curves || square || brace)
        return FALSE;
    else
        return TRUE;
}

int main(int argc, char ** argv)
{
    char *s = "([)]{}";
    if (! isValid(s)) 
        printf("Invalid\n");
    else
        printf("Valid\n");

    return 0;
}
