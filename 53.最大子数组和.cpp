/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    /* int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        for(int i = 0,last = 0;i < nums.size();i ++){
            last = nums[i] + max(last,0);
            res = max(res,last);
        }
        return res;
    } */
    /*******************************/
    struct Node
    {
        int sum,s,ls,rs;
    };
    Node build(vector<int>& nums,int l ,int r){
        if(l == r) {
            int v = max(nums[l],0);
            return {nums[l],v,v,v};
        }
        int mid = l + r >> 1;
        auto L = build(nums,l,mid),R = build(nums,mid+ 1,r);
        Node res;
        res.sum = L.sum + R.sum;
        res.s = max(max(L.s, R.s), L.rs + R.ls);
        res.ls = max(L.ls,L.sum + R.ls);
        res.rs = max(R.rs,R.sum + L.rs);
        return res;
    } 
    int maxSubArray(vector<int> &nums)
    {
        int res = INT_MIN;
        for (auto x : nums)
            res = max(res, x);
        if (res < 0)
            return res;
        auto t = build(nums, 0, nums.size() - 1);
        return t.s;
    }
};
// @lc code=end

