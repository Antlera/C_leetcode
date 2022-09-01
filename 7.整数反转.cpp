/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
public:
    /* int reverse(int x) {
        long long r = 0;
        while (x)
        {
            r = r * 10 + x % 10;
            x /= 10;
        }
        if(r > INT_MAX)return 0;
        if(r < INT_MIN)return 0;
        return r;
    } */
    int reverse(int x) {
        int r = 0;
        while (x)
        {
            if (r > 0 && r > (INT_MAX - x % 10) / 10)
                return 0;
            if (r < 0 && r < (INT_MIN - x % 10) / 10)
                return 0;
            r = r * 10 + x % 10;
            x /= 10;
        }
        return r;
    }
    
};
// @lc code=end

