/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        pair<int,int> res(INT_MAX,INT_MAX);//pair用于边运算边保存
        for(int i = 0;i < nums.size();i++)
            for(int j = i + 1,k = nums.size() - 1; j < k;j++){
                while (k - 1 > j && nums[i] + nums[j] + nums[k-1] >= target) k--;//规定查找的单调性方向
                int s = nums[i] + nums[j] + nums[k];//找到先求值
                //大于等于的情况
                res = min(res,make_pair(abs(s-target),s)); 
                if(k - 1 > j){
                    //小于的情况
                    s = nums[i] + nums[j] + nums[k-1];
                    res = min(res, make_pair(target - s, s));
                }
            }
        return res.second;
    }
};
// @lc code=end

