#include <stdio.h>


/* no extra space */
int removeDuplicates(int* nums, int numsSize) {
    if (nums == NULL || numsSize == 0)   return 0;
    
    int left = numsSize - 1;
    int i = 0, j = 1, new = 1;
    while(left) {
        left--;
        if (nums[i] == nums[j]) {
            nums[i] = nums[j];
        }
        else {
            if (j-i > 1) {
                nums[i+1] = nums[j];
            }
            new++;
            i++;
        }
        j++;
    }
    return new;
}

int main(int argc, char **argv)
{
    int nums[] = {1};
    int numsSize = sizeof(nums)/sizeof(int);
    int new, i;
    new = removeDuplicates(nums, numsSize);
    for (i=0; i<new; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}

