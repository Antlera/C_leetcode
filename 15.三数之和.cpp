/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i = 0;i < nums.size();i++){
            if(i && nums[i] == nums[i - 1]) continue;
            for(int j = i + 1,k = nums.size() - 1; j < k;j ++){
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;//若上一个下一个相等则跳过
                while (j < k - 1 && nums[i] + nums[j] + nums[k - 1] >= 0) k --;//指针移动试探
                if (nums[i] + nums[j] + nums[k] == 0)//i，j确定则k确定因此k无需跳过
                    res.push_back({nums[i], nums[j], nums[k]});
            }
        }
        return res;
    }
};
// @lc code=end

