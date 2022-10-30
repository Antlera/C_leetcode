/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;//组合问题确定顺序即可去重
    vector<int> path;
    vector<vector<int>> combine(int n, int k) {
        dfs(n,k,1);//到n中能选k个数，从1开始
        return ans;
    }
    void dfs(int n,int k ,int start){
        if(!k){
            ans.push_back(path);
            return;
        }
        for(int i = start;i <=n;i++){//搜索过的数则不去搜索，传入开始位置
            path.push_back(i);
            dfs(n,k-1,i+1);
            path.pop_back();
        }
    }
};
// @lc code=end

