/*
 * @lc app=leetcode.cn id=1 lang=c
 *
 * [1] 两数之和
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i+1; j < numsSize; j++)
        {
            if (nums[i]+nums[j]==target)
            {
                int *answer = (int *)malloc(2 * sizeof(int));
                answer[0] = i;
                answer[1] = j;
                *returnSize = 2;
                return answer;
            }
            
        }
        
    }
    //return NULL;
}
// @lc code=end

