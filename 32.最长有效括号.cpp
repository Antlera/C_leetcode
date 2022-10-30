/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int res = 0;
        for(int i = 0, start = -1; i < s.size();i ++){//遍历
            if(s[i] == '(')stk.push(i);//若为左括号则入栈
            else{
                if(stk.size()){//若栈内有可用左括号
                    stk.pop();//出栈配对
                    if(stk.size()){
                        //若仍有左括号，此时匹配到的最远为i-(stk.top+1)+1
                        res = max(res, i - stk.top());
                    }
                    else{
                        res = max(res, i - start);//若已经没有则直接使用start
                    }
                }
                else{
                    start = i;//为空则直接终止，调整start位置
                }
            }
        }
        return res;
    }
};
// @lc code=end

