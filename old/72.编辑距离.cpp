/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
class Solution {
public:
    int minDistance(string str1, string str2) {
        vector<vector<int>> dp(2, vector<int>(str2.size() + 1, 0));
    dp[0][0] = 0;
    dp[1][0] = 1;
    for (int j = 1; j <= str2.size(); j++)
    {
        dp[0][j] = j;
    }
    for (int i = 1; i <= str1.size(); i++)
    {
        dp[i%2][0] = i;
        for (int j = 1; j <= str2.size(); j++)
    {
        if (str1[i-1]==str2[j-1])
        {
            dp[i%2][j] = dp[(i - 1)%2][j - 1];
        }
        else{
            dp[i%2][j] = min(min(dp[(i - 1)%2][j], dp[i%2][j - 1]), dp[(i - 1)%2][j - 1]) + 1;
        }
        
    }
    }
    return dp[str1.size()%2][str2.size()];
    }
};
// @lc code=end

