/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> hs,ht;
        for (auto c:t) ht[c]++;//统计字串字符数

        string res;
        int cnt = 0;
        for(int i = 0,j = 0;i < s.size();i++){//遍历
            hs[s[i]]++;
            if(hs[s[i]]<=ht[s[i]])cnt++;//增加之后不大于说明有效

            while(hs[s[j]] > ht[s[j]]) hs[s[j++]]--;//处理头部的移动，即若总字符数超出，则可以剔除头部多余的字符
            if(cnt == t.size())
            {
                if(res.empty() || i - j + 1 < res.size()) res = s.substr(j,i - j + 1);//更新最小覆盖字串
            }
        }
        return res;
        
    }
};
// @lc code=end

