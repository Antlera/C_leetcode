/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> h;//利用hash表，若能找到target-nums[i]则返回，若找不到则继续插入
        for (int i = 0; i < nums.size(); i++)
        {
            int r = target - nums[i];
            if(h.count(r)) return {h[r],i};
            h[nums[i]] = i;
        }
        return {}; 
    }
};
// @lc code=end

