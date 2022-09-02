/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        if(strs.empty())return res;//空白特判
        for(int i = 0;;i++){
            if(i >= strs[0].size())return res;//特判达到第一个串的结尾，第一个大于
            char c  = strs[0][i];
            for(auto& str: strs)
                if(str.size() <= i || str[i] != c)
                    return res;
            res += c;
        }
    }
};
// @lc code=end

