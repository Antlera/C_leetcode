/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        for(int i = 0,j = 0;i < nums.size();i++){
            if(j < i) return false;
            j = max(j, i + nums[i]);//之前的所有跳跃中最远能够到达的
        }
        return true;
    }
};
// @lc code=end

