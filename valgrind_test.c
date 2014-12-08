/*valgrind  --leak-check=full ./a.out*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int argc,char *argv[])
{
/* forget free the memory - detected */
    char *lost = strdup("vanished in blackhole");
//    free(lost);
    lost = NULL;

/* uninitialized variable - detected */
    int condition;
    if (condition) 
        printf("Misuse of uninitialized value");

/* uninitialized variable -detected */
    int height;
    printf("I am %d inches tall.\n", height);

/* access invalid memory - should detected? */
    int vector[5] = {0};
    vector[5] = 1;

/* uninitialized memory - should detected? */
    char *buffer = malloc(10);
    memcpy(buffer, "hello\n", 7);
    printf("%s", buffer);
    free(buffer);

    return 0;
}

