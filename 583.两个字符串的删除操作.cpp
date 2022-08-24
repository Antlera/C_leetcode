/*
 * @lc app=leetcode.cn id=583 lang=cpp
 *
 * [583] 两个字符串的删除操作
 */

// @lc code=start
class Solution {
public:
    int minDistance(string str1, string str2) {
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
    return str1.size() +str2.size() - 2 * dp[str1.size()%2][str2.size()];
    }
};
// @lc code=end

