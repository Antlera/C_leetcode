/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(auto c: s){
            if(c == '(' ||c == '['|| c =='{') stk.push(c);//若为左括号入栈
            else{
                if (stk.size() && abs(stk.top() - c) <= 2)//查找ASCII码规律
                    stk.pop();
                else return false;
            }
        }
        return stk.empty();
    }
};
// @lc code=end

