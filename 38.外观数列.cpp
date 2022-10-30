/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

// @lc code=start
class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for (int i = 0; i < n - 1; i++)
        {
            string t;
            for(int j = 0;j < s.size();){
                int k = j + 1;
                while (k < s.size() && s[k] == s[j]) k ++;//统计直到找到第一个不等
                t += to_string(k - j) + s[j];//实际上是k-1 - j + 1
                j = k; 
            }
            s = t;
        }
        return s;
        
    }
};
// @lc code=end

