#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *smallerNumbersThanCurrent(int *nums, int numsSize, int *returnSize)
{
    int *res = (int *)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    int hash[101] = {0};
    for (int i = 0; i < numsSize; i++)
    {
        hash[nums[i]]++;
    }
    for (int i = 0; i < numsSize; i++)
    {
        int cnt = 0;
        for (int j = 0; j < nums[i]; j++)
        {
            if (hash[j])
            {
                cnt += hash[j];
            }
        }
        res[i] = cnt;
    }
    return res;
}