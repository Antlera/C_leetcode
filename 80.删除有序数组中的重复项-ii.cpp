/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;//下标
        for(auto x: nums)
            if(k < 2 || nums[k - 1] != x || nums[k - 2] != x)//若前两个不是x则保存，若是则跳过
                nums[k++] = x;
        return k;
    }
};
// @lc code=end

