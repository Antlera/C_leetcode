/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty())return{-1,-1};
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = l + r >> 1;
            if(nums[mid]>=target)r=mid;
            else l = mid + 1;
        }
        if(nums[l]!=target)return {-1,-1};
        int L = l;
        l = 0, r = nums.size()-1;
        while (l < r)
        {
            int mid = l + r + 1>> 1;
            if (nums[mid] <= target) l = mid;
            else r = mid -1;
        }
        return {L,r}; 
    }
};
// @lc code=end

