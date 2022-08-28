/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        for(int i = 0; i < s.size();i ++)
        {
            int l = i - 1, r = i + 1;
            while (l >= 0 && r < s.size() &&s[l] == s[r]) l -- ,r ++;//以i为中心向两边探测,直到检查到不符合回文的情况
            if(res.size() < r - l - 1) res = s.substr(l + 1, r - l - 1);//若找到更长串，则替换

            l = i, r = i + 1;
            while (l >= 0 && r < s.size() &&s[l] == s[r]) l -- ,r ++;//以i为中心向两边探测,直到检查到不符合回文的情况
            if(res.size() < r - l - 1) res = s.substr(l + 1, r - l - 1);//若找到更长串，则替换
            
        }
        return res;
    }
};
// @lc code=end

