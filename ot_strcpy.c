/* my implement of strcpy
 * Test case:
 * 1. Null destination, Null source
 * 2. source is longer than destination
 * 3. source is the destination
 * */

char des[32];
char input[64];
char *
ot_strcpy(char *des, const char *src)
{
    if (des == NULL) {
        printf("destination address is invalid\n");
        return des;
    }
    if (src == NULL){
        printf("source address is NULL, nothing to copy\n");
        return des;
    }
}

int 
main(void)
{
    while (1) {
        printf("\ninput the string to be copyed: ");
        scanf("%s\n", input);
        ot_strcpy(des, input);
    }
}

