/*
 * @lc app=leetcode.cn id=35 lang=c
 *
 * [35] 搜索插入位置
 */

// @lc code=start


int searchInsert(int* nums, int numsSize, int target){
    int high = numsSize - 1;
    int low = 0;
    int middle;
    while (low<=high)
    {
        middle = low + (high - low) / 2;
        if(nums[middle]<target){
            low = middle + 1;
        }
        else if(nums[middle]>target){
            high = middle - 1;
        }
        else{
            return middle;
        }
    }
    if (nums[middle] < target)
    {
        return middle + 1;
    }
    if (nums[middle] < target)
    {
        return middle + 1;
    }
    else{
        return middle;
    }
}
// @lc code=end

