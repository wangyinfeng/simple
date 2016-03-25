//https://leetcode.com/problems/single-number/
//Let's see how stupid you are.
#include <stdio.h>

int singleNumber(int* nums, int numsSize) {
    if (nums == NULL || numsSize<=2)
        return -1;
    int i, j;
    for (i=0; i<numsSize; i++) {
        for (j=i+1; j<numsSize; j++) {
            if (nums[i] == nums[j])
                continue;
            else if (j == numsSize -1)
                return i;
        }
    }
    return -2;
}

int main(int argc, char **argv)
{
    int nums[] = {1, 3, 1, 5, 0, 5, 0};
    int numsSize = sizeof(nums)/sizeof(int);
    int num = singleNumber(nums, numsSize);
    if (num >=0 && num < numsSize)
        printf("The number %d in position %d is single.\n", nums[num], num);
    else
        printf("Invalid!\n");
    return 0;
}

