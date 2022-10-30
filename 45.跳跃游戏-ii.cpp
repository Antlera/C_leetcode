/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n);//到达某坐标的最少步数

        for(int i = 1,j = 0;i < n;i++){
            while (j + nums[j] < i) j++;//从小到大枚举找到最小的能够到达i的坐标，由其坐标推出即可
            f[i] = f[j] + 1;
        }
        return f[n - 1];
    }
};
// @lc code=end

