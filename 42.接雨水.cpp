/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> stk;
        int res = 0;
        for(int i = 0;i < height.size();i++){
            int last = 0;//如果不是底且有高度，只会是最靠近i的栈顶元素，即因为0是可能的最低栈顶，因此一定是最靠近的，否则则是无间隙的
            while(stk.size() && height[stk.top()] <= height[i]){
                res += (height[stk.top()] - last) * (i - stk.top() - 1);//i与栈顶的包围部分
                last = height[stk.top()];//更新底部
                stk.pop();
            }

            if(stk.size()) res += (height[i] - last)*(i - stk.top() - 1);//最后一次的高于i位 
            stk.push(i);
        }
        return res;
    }
};
// @lc code=end

