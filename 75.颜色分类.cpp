/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
public:
    //三指针
    void sortColors(vector<int>& nums) {
       for(int i  = 0,j = 0,k = nums.size()-1;i <= k;) {
           if (nums[i] == 0)
               swap(nums[i++], nums[j++]);
           else if (nums[i] == 2)
               swap(nums[i], nums[k--]);
           else
               i++;
       }
    }
};
// @lc code=end

