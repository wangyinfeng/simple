#include <stdio.h>

/*
void moveZeroes(int* nums, int numsSize) {
    int i, j, n = 0;
    if (nums == NULL || numsSize <0)
        return;
    // a little silly here
    for (i=0; i<numsSize; i++) {
        if (nums[i] == 0)
            n++;
    }

    for (i=0; i<numsSize; i++) {
        if (i > 0 && nums[i-1] == 0 && n-->0)
            i--;
        if (nums[i] == 0) {
            for (j=i; j<numsSize-1; j++)
                nums[j] = nums[j+1];
            nums[numsSize-1] = 0;
        }
    }
}
*/

/*This way is much more decent, clear and easy to understand
 * performance 4 times better than the above */
void moveZeroes(int* nums, int numsSize) {
    int i=0, j=0;
    while (i<numsSize) {
        if (nums[i]!=0){
            nums[j]=nums[i];
            j++;
            i++;
        } 
        else {
            i++;
        }
    }
    while (j<numsSize){
        nums[j]=0;
        j++;
    }
}
int main(int argc, char **argv)
{
    int i;
    int nums[] = {0,0,1,2,0,0,4,0,5};
    //int nums[] = {1, 0,0,0,0,0};
    int numsSize = sizeof(nums)/sizeof(int);
    moveZeroes(nums, numsSize);
    for (i=0; i<numsSize; i++)
        printf("%d ", nums[i]);
    printf("\n");

    return 0;
}

