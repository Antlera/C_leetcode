/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    //去重的重要方法，确定顺序！
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;//答案集合
        int n = nums.size();
        for(int i = 0; i < 1 << n;i ++){//遍历0~2^n-1,即遍历了所有选择的可能方案
            vector<int> path;
            for(int j = 0;j < n;j++){
                if(i >> j & 1)  path.push_back(nums[j]);//若第n位选择了，则push
            }
            ans.push_back(path);
        }
        return ans;
    }
};
// @lc code=end

