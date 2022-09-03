/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:
    vector<string> ans;
    string strs[10] = {
        "","","abc","def",
        "ghi","jkl","mno",
        "pqrs","tuv","wxyz"
    };
    void dfs(string &digits,int u,string path){
        if(u == digits.size()) ans.push_back(path);
        else{
            for(auto c : strs[digits[u] - '0'])
                dfs(digits,u + 1,path + c);
        }
    }
    vector<string> letterCombinations(string digits) { 
        if (digits.empty()) return ans; 
        dfs(digits,0,"");
        return ans;
    }
};
// @lc code=end

