/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 1;
        while(--n){
            int c = a + b;
            a = b,b = c;
        }
        return b;
    }
};
// @lc code=end

