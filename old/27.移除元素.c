/*
 * @lc app=leetcode.cn id=27 lang=c
 *
 * [27] 移除元素
 */

// @lc code=start


int removeElement(int* nums, int numsSize, int val){
    int *slow = nums, *fast = nums;
    if (!numsSize)
    {
        return 0;
    }
    while (fast-&nums[numsSize])
    {
        if (*fast!=val)
        {
            *slow = *fast;
            slow++;
        }
        fast++;
    }
    return slow - nums;
}
// @lc code=end

