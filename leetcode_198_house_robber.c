#include <stdio.h>

int rob(int* nums, int numsSize) {
    if (nums == NULL || numsSize < 1)
        return 0;
    /* The starightforward way is count each possible */
    int i, rob_a=0, rob_b=0, rob_c=0;
    for (i=0; i<numsSize; i++) {
        rob_a += nums[i];
        if ((i+1) < numsSize)
            rob_b += nums[i+1];
        i++;
    }
    if (numsSize > 3)
        rob_c = nums[0] + nums[numsSize-1];

    if (rob_a > rob_b) {
        if (rob_a > rob_c)
            return rob_a;
        else 
            return rob_c;
    }
    else {
        if (rob_b > rob_c)
            return rob_b;
        else 
            return rob_c;
    }
}

int main(int argc, char **argv)
{
    //int nums[] = {1,1,1,1,1,2};
    //int nums[] = {5,11,9,100,2};
    //int nums[] = {2,1,1,2};
    int nums[] = {1,3,1,3,100};
    int numsSize = sizeof(nums)/sizeof(int);
    printf("harvest %d\n", rob(nums, numsSize));

    return 0;
}

