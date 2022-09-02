/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        for(int i = 0,j = height.size() - 1;i < j;){
            res = max(res,min(height[i],height[j])*(j-i));//更新最大值
            if(height[i]>height[j])j--;//移动较小边
            else i++;
        }
        return res;
    }
};
// @lc code=end

