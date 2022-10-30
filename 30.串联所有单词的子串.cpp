/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 */

// @lc code=start
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (words.empty())
            return res;
        int n = s.size(), m = words.size(), w = words[0].size();
        unordered_map<string,int> tot;
        for(auto &word :words) tot[word]++;//统计单词总数

        for(int i = 0; i < w;i++){
            unordered_map<string,int> wd;//窗口内部的单词统计
            int cnt = 0;
            for(int j = i; j + w <= n/*保证窗口可以移动*/;){//滑动窗口双指针，即j - m * w & j 下一个移动
                if(j >= i + m * w){//窗口长度足够，则需要开始删除最前面的元素
                    auto word = s.substr(j - m * w, w);
                    wd[word]--;
                    if(wd[word] < tot[word]) cnt--;
                }
                auto word = s.substr(j,w);//窗口准备向前移动一位
                wd[word]++;
                if(wd[word] <= tot[word])cnt++;
                if(cnt == m) res.push_back(j - (m - 1) * w);
                j += w;//窗口右边缘向后移动
            }
        }
        return res;
    }
};
// @lc code=end

