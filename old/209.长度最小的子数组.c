/*
 * @lc app=leetcode.cn id=209 lang=c
 *
 * [209] 长度最小的子数组
 */

// @lc code=start


int minSubArrayLen(int target, int* nums, int numsSize){
    int subLen = numsSize+1;
    if(!numsSize){
        return 0;
    }
    int high = 0;
    int low = 0;
    int subSum = 0;
    while (subSum < target)
    {
        subSum = 0;
        for (int i = low; i <= high; i++)
        {
            subSum += nums[i];
        }
        if (high - low + 1 < subLen)
        {
            subLen = high - low + 1;
        }
        high++;
    }
    while (high<numsSize)
    {
        while (subSum<target)
        {
            subSum = 0;
            low++;
            for (int i = low; i <= high; i++)
            {
                subSum += nums[i];
            }
        }
        if(high-low+1<subLen){
            subLen = high - low + 1;
        }
        high++;
    }
    // if (subLen==numsSize+1)
    // {
    //     return 0;
    // }
    // else{
    //     return subLen;
    // }
    return subLen;
}
// @lc code=end

