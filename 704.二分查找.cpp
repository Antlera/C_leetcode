/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */
#include<vector>
// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int middle = (left + right) / 2;
        while (left<=right)
        {
            if (nums[middle]<target)
            {
                left = middle + 1;
                middle = (left + right) / 2;
            }
            if (nums[middle]>target)
            {
                right = middle - 1;
                middle = (left + right) / 2;
            }
            if (nums[middle]==target)
            {
                return middle;
            }
        }
        return -1;
    }
};
// @lc code=end

