/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();     //柱子高度数组大小
        vector<int> left(n),right(n); //利用单调栈获得左右第一个小于当前高度的柱子
        stack<int> stk;   //单调栈

        for(int i = 0;i < n;i ++){
            while (stk.size() && h[stk.top()] >= h[i])
                stk.pop();//若栈不为空，且栈顶元素大于当前元素，则持续出栈
            if (stk.empty())
                left[i] = -1;//若出栈完成，栈为空，则第一个小于元素可设置为边界
            else
                left[i] = stk.top();  //若不为空则栈顶元素即为第一个小于当前元素的柱子
            stk.push(i);//入栈当前元素
        }
        stk = stack<int>();

        for (int i = n - 1; i >= 0; i--)
        {
            while (stk.size() && h[stk.top()] >= h[i])
                stk.pop();
            if (stk.empty())
                right[i] = n;
            else
                right[i] = stk.top();
            stk.push(i);
        }

        int res = 0;
        for(int i = 0;i < n;i ++) res = max(res,h[i] * (right[i] - left[i] - 1)); //按顶边枚举所有矩形，找到最大的矩形
        return res;
    }
};
// @lc code=end

