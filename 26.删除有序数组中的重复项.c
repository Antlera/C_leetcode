/*
 * @lc app=leetcode.cn id=26 lang=c
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start


int removeDuplicates(int* nums, int numsSize){
    int *slow = nums, *fast = nums;
    if (!numsSize)
    {
        return 0;
    }
    while (fast-&nums[numsSize-1])
    {
        if(*(fast+1)!=*fast){
            ++slow;
            *slow = *(fast + 1);
        }
        fast++;
    }
    return (slow - nums + 1);
}
// @lc code=end

