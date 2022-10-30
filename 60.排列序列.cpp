/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 排列序列
 */

// @lc code=start
class Solution {
public:
/*     string getPermutation(int n, int k) {
        string res;
        for(int i = 1;i <= n;i ++) res += to_string(i);
        for(int i = 0;i < k - 1;i ++){
            next_permutation(res.begin(),res.end());
        }
        return res;
    }//O(n!*k) */
    int facts[10]={1};
    string getPermutation(int n, int k)
    {
        for (int i = 1; i < 10; i++)
            facts[i] = facts[i - 1] * i;
        
        string res;
        vector<bool> st(10);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                if(!st[j]){
                    if (facts[n - i] < k)
                        k -= facts[n - i];
                    else{
                        res += to_string(j);
                        st[j] = true;
                    }
                }
            }
        return res;
    }
};
// @lc code=end

