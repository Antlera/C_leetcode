/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
public:
    int n;
    vector<bool> col,udg,dg;
    vector<string> path;
    vector<vector<string>> ans;
    vector<vector<string>> solveNQueens(int _n) {
        n = _n;
        col = vector<bool>(n);
        dg = udg = vector<bool>(n * 2);
        path = vector<string>(n,string(n,'.'));

        dfs(0);
        return ans;
    }
    void dfs(int u){
        if(u == n){
            ans.push_back(path);
            return;
        }
        for(int i = 0;i < n;i++){
            if(!col[i] && !dg[u - i + n] && !udg[u + i]){
                col[i] = dg[u - i + n] = udg[u + i] = true;
                path[u][i] = 'Q';
                dfs(u + 1);
                path[u][i] = '.';
                col[i] = dg[u - i + n] = udg[u + i] = false; 
            }
        }
    }
};
// @lc code=end

