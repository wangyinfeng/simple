/*====================================================================
 * Description: Practice the merge sorting
 * The basic idea is merge the sorted subsequence.
 *     1 3 3 5 6 7        ^ sorted sequence
 *    1 3 5 6       3 7   |
 *   3 5     1 6    3 7   ^
 *  3  5    1  6    7  3  |initial sequence waitting for sorting
 *  Recursion is the most straightforward way for this problem.
 * DATE: 2014/06/12
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
#define RANDOM_NUMBER   "random.number"

/* read number from random.number, sorting them then print out the result */
int
init_sorting_data(int **data, char *src_file)
{
    FILE *fd;
    char ch;
    char line_content[32]; 
    unsigned int lines = 0, i = 0;
    fd = fopen(RANDOM_NUMBER, "r");
    if (fd == NULL) {
        fprintf(stderr, "Failed to open %s\n", RANDOM_NUMBER);
        return 0;
    }
    while ((ch=fgetc(fd)) != EOF) {
        if ((ch == '\n') || (ch == '\r'))
            ++lines;
    }
    fclose(fd);

    *data = (int *)malloc(lines*sizeof(int)); /* should be released correctly */
    fd = fopen(RANDOM_NUMBER, "r");
    while (fgets(line_content, sizeof(line_content), fd) != NULL) {
        *(*data+i) = atoi(line_content);
        i++;
    }

    fclose(fd);
    return lines;
}

void
print_data(int **data, unsigned int len)
{
    unsigned int i;
    for (i=0; i<len; i++) {
        printf("%d ", *(*data+i));
    }
    printf("\n");
}

void
merge(int *left, unsigned int left_len, int *right, unsigned int right_len)
{
    int i=0, j=0, k=0, n=0;
    /* extra space! */
    int *temp = malloc((left_len+right_len)*sizeof(int));

    /* compare the right and left element, one by one */
    while ( (i<left_len) && (j<right_len) ) {
        if (left[i] < right[j]) 
            temp[k++] = left[i++];
        else
            temp[k++] = right[j++];
    }
    /* all elements are compared, and the lefts are the bigger ones */
    while (i<left_len) {
        temp[k++] = left[i++];
    }
    while (j<right_len) {
        temp[k++] = right[j++];
    }
    /* release the temp */
    for (n=0; n<(left_len+right_len); n++) {
        left[n] = temp[n];
    }

    free(temp);    
}

void
merge_sort(int **data, unsigned int len)
{
    int *left, *right;
    int left_len, right_len;
    /* divid the list until compare one by one */
    if (len >1) {
        left = *data;
        left_len = len/2;
        right = *data+len/2;
        right_len = len - left_len;

        merge_sort(&left, left_len);
        merge_sort(&right, right_len);
        merge(left, left_len, right, right_len);
    }
}

int
main(int argc, char **argv)
{
    int *data;
    unsigned int data_len = init_sorting_data(&data, RANDOM_NUMBER);
    if (!data_len) {
        fprintf(stderr, "Init data from file failed\n");
        exit(1);
    }
    merge_sort(&data, data_len);
    print_data(&data, data_len);
    free(data);
    return 0;
}

