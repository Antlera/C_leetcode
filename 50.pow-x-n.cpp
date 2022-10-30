/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        typedef long long LL;
        bool is_minus = n < 0;
        double res = 1;
        for(LL k = abs(LL(n));k;k >>= 1){
            if(k & 1) res *= x;
            x *= x;//反复平方法
        }
        if(is_minus) res = 1/res;
        return res;
    }
};
// @lc code=end

