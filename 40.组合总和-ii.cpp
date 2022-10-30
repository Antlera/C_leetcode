/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    bool st[105];
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        // memset(st,0,sizeof st);
        sort(c.begin(),c.end());
        dfs(c,0,target);
        return ans;
    }
    void dfs(vector<int>& c,int u,int target){
        if(target == 0){
            ans.push_back(path);
            return;
        }
        if(u == c.size()) return;
        int k = u + 1;
        while (k < c.size() && c[k] == c[u])k ++;

        int cnt = k - u;

        for(int i = 0; c[u] * i <= target && i <= cnt;i ++){
            dfs(c,k,target - c[u] * i);
            path.push_back(c[u]);
        }

        for(int i = 0;c[u] * i <= target && i <= cnt;i++){
            path.pop_back();
        }
    }
/*     void dfs(vector<int> &c, int u, int target)
    {
        if(target == 0){
            cout << "YES" << endl;
            ans.push_back(path);
            return;
        }
        if(u == c.size()) return;

        for(int i = 0; i < c.size();i ++){
            cout << i << endl;
            if (!st[i] && target - c[i] >= 0 && (path.empty() || c[i] >= path.back()))
            {
                path.push_back(c[i]);
                st[i]= true;
                dfs(c, u + 1, target - c[i]);
                st[i] = false;
                path.pop_back();
            }
        }
    } */
};
// @lc code=end

