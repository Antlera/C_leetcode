/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
using namespace std;
#include<vector>
#include<string>
class Solution {
public:
    int longestCommonSubsequence(string str1, string str2) 
    {
        int min_length = min(str1.size(), str2.size());
        vector<int> dp(min_length+1,0);
    if (str1.size()<str2.size())
    {
        int cur = 1;
        for (int i = 1; i <= str1.size();i++)
        {
            for (int j = cur; j <= str2.size(); j++)
            {
                if (str1[i-1]==str2[j-1]) 
                {
                    dp[i] = dp[i - 1] + 1;
                    cur = j+1;
                    break;
                    
                }
                else{
                    dp[i] = max(dp[i - 1], dp[i]);
                }
                
            }  
        }
    }
    else{
        int cur = 1;
        for (int i = 1; i <= str2.size();i++)
        {
            for (int j = cur; j <= str1.size(); j++)
            {
                if (str2[i-1]==str1[j-1])
                {
                    dp[i] = dp[i - 1] + 1;
                    cur = j+1;
                    break;
                }
                else{
                    dp[i] = max(dp[i - 1], dp[i]);
                }
                
            }  
        }
    }
        return dp[min_length];
    }
};
// @lc code=end

