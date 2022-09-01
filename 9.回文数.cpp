/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return 0;
        int t = x;
        long long res = 0;
        while (x)
        {
            res = res * 10 + x % 10;
            x /= 10;
        } 
        return res == t;
    }
  /*   bool isPalindrome(int x) {
        if(x < 0) return 0;
        string s = to_string(x);
        return s == string(s.rbegin(),s.rend());
    } */

};
// @lc code=end

