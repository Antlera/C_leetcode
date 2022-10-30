/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for(int i = 0;i < nums.size();i++)
            if(nums[i]!=val)//只保留不等于该val的值
                nums[k++] = nums[i];
        return k;
    }
};
// @lc code=end

