/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    //卡特兰数的应用
    vector<string> ans;
    void dfs(int n, int lc, int rc, string seq){
        if(lc == n && rc == n)ans.push_back(seq);//左右括号数量必须相等
        else{
            if (lc < n)
                dfs(n, lc + 1, rc, seq + '(');
            if (rc < n && lc > rc)//任意前缀中左括号数量大于等于右括号
                dfs(n, lc, rc + 1, seq + ')');
        }
    }
    vector<string> generateParenthesis(int n) {
        dfs(n,0,0,"");
        return ans;
    }
};
// @lc code=end

