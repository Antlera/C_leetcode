/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */

// @lc code=start
class Solution {
public:
    int n;
    int ans;
    vector<bool> col,dg,udg;
    int totalNQueens(int _n) {
        n = _n;
        col = vector<bool>(n);
        dg = udg = vector<bool>(2*n);

        dfs(0);
        return ans;
    }
    void dfs(int u){
        if(u == n){
            ans++;
            return;
        }
        for(int i = 0;i < n;i ++){
            if(!col[i]&&!dg[u - i + n]&&!udg[u + i]){
                col[i] = dg[u - i + n] = udg[u + i] = true;
                dfs(u + 1);
                col[i] = dg[u - i + n] = udg[u + i] = false;
            }
        }
    }
};
// @lc code=end

