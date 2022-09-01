/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p)
    {
        int n = s.size(), m = p.size();
        s = ' ' + s, p = ' ' + p;
        vector<vector<bool>> f(n + 1, vector<bool>(m + 1));
        f[0][0] = true;
        for (int i = 0; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                if (j + 1 <= m && p[j + 1] == '*')
                    continue;
                if (i && p[j] != '*')
                {
                    f[i][j] = f[i - 1][j - 1] && (s[i] == p[j] || p[j] == '.');
                }
                else if (p[j] == '*')
                {
                    for (int k = i; k >= 0; k--)
                    { //*匹配的字符个数，从i到0
                        f[i][j] = f[i][j] || f[i - k][j - 2];
                        if (f[i][j])
                            for (int l = 0; l < k; l++) //前面匹配完成之后，后面需要单独匹配的次数
                                f[i][j] = f[i][j] && (s[i - l] == p[j - 1] || p[j - 1] == '.');
                    }
                }
            }
        return f[n][m];
    }
/*     bool isMatch(string s, string p)
    {
        int n = s.size(), m = p.size();
        s = ' ' + s, p = ' ' + p;
        vector<vector<bool>> f(n + 1, vector<bool>(m + 1));
        f[0][0] = true;
        for (int i = 0; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                if (j + 1 <= m && p[j + 1] == '*')
                    continue;
                if (i && p[j] != '*')
                {
                    f[i][j] = f[i - 1][j - 1] && (s[i] == p[j] || p[j] == '.');//即前i-1, j-1部分均满足，然后匹配之后的单个字符
                }
                else if (p[j] == '*')
                {
                    f[i][j] = f[i][j - 2] || i && f[i - 1][j] && (s[i] == p[j - 1] || p[j - 1] == '.');//正则匹配式向前推2个字符，讨论被匹配字符串已经有多少已经被匹配
                }
            }
        return f[n][m];
    } */
};
// @lc code=end

