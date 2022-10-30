/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        int l = 0,r = x;
        while(l < r){
            int mid = l + 1ll + r >> 1;
            if(mid  <= x /mid ) l = mid ;
            else r = mid - 1;
        }
        return l;
    }
};
// @lc code=end

