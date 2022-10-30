/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<bool> st;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        path = vector<int>(nums.size());
        st = vector<bool>(nums.size());
        sort(nums.begin(),nums.end());
        dfs(nums, 0);
        return ans;
    }
    void dfs(vector<int> nums, int u)
    {
        if (u == nums.size())
        {
            ans.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if(!st[i]){
                if (i && nums[i] == nums[i - 1] && !st[i - 1])//对相同元素保证顺序即可保证不重复，原理是对相同元素打了顺序标签，
                    continue;
                else
                {
                    path[u] = nums[i];
                    st[i] = true;
                    dfs(nums, u + 1);
                    st[i] = false;
                }
            }
        }
    }
};
// @lc code=end

