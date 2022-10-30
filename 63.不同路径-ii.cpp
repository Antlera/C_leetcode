/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        int n = o.size();
        if(!n) return 0;
        int m = o[m].size();

        vector<vector<int>> f(n,vector<int>(m));
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                if(!o[i][j])
                {
                    if(!i&&!j) f[i][j] = 1;
                    else{
                        if (i) f[i][j] += f[i-1][j];
                        if(j) f[i][j] += f[i][j-1];
                    }
                }
        return f[n-1][m-1];
    }
};
// @lc code=end

