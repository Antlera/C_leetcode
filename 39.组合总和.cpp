/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<vector<int>> combinationSum(vector<int>& cs, int target) {
        dfs(cs,0,target);
        return ans;
    }
    void dfs(vector<int> &cs,int u ,int target)
    {
        if(target == 0){
            ans.push_back(path);
            return;
        }
        if(u == cs.size()) return;
        for(int i = 0;cs[u] * i <= target;i ++){
            dfs(cs,u + 1,target - cs[u] * i);
            path.push_back(cs[u]);
        }

        for(int i = 0; cs[u] * i <= target; i++){
            path.pop_back();
        }
    }
};
// @lc code=end

