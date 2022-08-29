/*
 * @lc app=leetcode.cn id=977 lang=c
 *
 * [977] 有序数组的平方
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize){
    int low = 0;
    int high = numsSize - 1;
    int *result = (int *)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    for (int i = numsSize-1; i >= 0; i--)
    {
        if (nums[low] * nums[low] < nums[high] * nums[high])
        {
            result[i] = nums[high] * nums[high];
            high--;
        }
        else{
            result[i] = nums[low] * nums[low];
            low++;
        }
    }
    return result;
}
// @lc code=end

