/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(),digits.end());
        int t = 1;
        for(auto & x: digits){
            t += x;
            x = t % 10;
            t /= 10;
        }
        if(t) digits.push_back(t);
        reverse(digits.begin(),digits.end());
        return digits;
    }
};
// @lc code=end

