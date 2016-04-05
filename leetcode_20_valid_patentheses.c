#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isValid(char* s) {
#define FALSE   0
#define TRUE    1
    int curves = 0, square = 0, brace = 0, len, i;
    int next_right = 0; // 1 - right curve; 2 - right square; 3 - right brace;
    if (s == NULL)
        return FALSE;

    len = strlen(s);
    if (len == 0) return TRUE;
    for (i=0; i<len; i++){
        switch (s[i]){
            case '(': curves++; next_right = 1; break;
            case ')': curves--; next_right = 0; break;
            case '[': square++; next_right = 2; break;
            case ']': square--; next_right = 0; break;
            case '{': brace++; next_right = 3; break;
            case '}': brace--; next_right = 0; break;
            default:
                break;
        }
        
        if (i <len-1 && next_right) {
            if (s[i+1] == ')' || s[i+1] == ']' || s[i+1] == '}') {
                switch (next_right){
                    case 1: 
                        if (s[i+1] != ')') return FALSE;
                        else break;
                    case 2:
                        if (s[i+1] != ']') return FALSE;
                        else break;
                    case 3:
                        if (s[i+1] != '}') return FALSE;
                        else break;
                    default:
                        break;
                }
            }
        }
        
    }
    if (curves || square || brace)
        return FALSE;
    else
        return TRUE;
}

int main(int argc, char ** argv)
{
    //char *s = "([)]{}";
    char *s = "[([]])";
    //char *s = "((())[{()}])";
    if (! isValid(s)) 
        printf("Invalid\n");
    else
        printf("Valid\n");

    return 0;
}
