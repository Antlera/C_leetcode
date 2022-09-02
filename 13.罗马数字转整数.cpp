/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> hash;
        hash['I'] = 1,hash['V'] = 5,
        hash['X'] = 10,hash['L'] = 50,
        hash['C'] = 100,hash['D'] = 500,
        hash['M'] = 1000;//哈希表对应回值

        int res = 0;
        for(int i = 0;i < s.size();i++){
            //观察可以发现，除了4，9以外都可以转为单个字母对应值相加，只有4，9是前小于后，特判减去即可
            if(i + 1 < s.size() && hash[s[i]] < hash[s[i+1]])
                res -= hash[s[i]];
            else    res += hash[s[i]];
        }
        return res;
    }
};
// @lc code=end

