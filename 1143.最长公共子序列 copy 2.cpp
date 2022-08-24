/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string str1, string str2) 
    {
        vector<vector<int>> dp(2, vector<int>(str2.size() + 1, 0));
    for (int i = 1; i <= str1.size(); i++)
    {
        for (int j = 1; j <= str2.size(); j++)
        {
            if (str1[i-1]==str2[j-1])
            {
                dp[i%2][j] = dp[(i - 1)%2][j - 1] + 1;
            }
            else{
                dp[i%2][j] = max(dp[(i - 1)%2][j], dp[i%2][j - 1]);
            }
            
        }
        
    }
    return dp[str1.size()%2][str2.size()];
    }
};
// @lc code=end

