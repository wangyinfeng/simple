//https://leetcode.com/problems/single-number/
//Let's see how stupid you are.
#include <stdio.h>

int singleNumber(int* nums, int numsSize) {
    if (nums == NULL)
        return -1;
    int result = 0;
    int i;
    for (i=0; i<numsSize; i++){
        /* It's bloody trick to use the XOR to determine the same number
         * of number 2. XOR not work for odd numbers.
         * Another way is to sort the array then count the same number */
        result ^= nums[i];
    }
    return result;
}

int main(int argc, char **argv)
{
    int nums[] = {1, 3, 1, 5, 3, 5, 0};
    //int nums[] = {1};
    int numsSize = sizeof(nums)/sizeof(int);
    int num = singleNumber(nums, numsSize);
    printf("The number %d is single.\n", num);
    return 0;
}

