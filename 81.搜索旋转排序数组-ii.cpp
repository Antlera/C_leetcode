/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty()) return false;
        int R = nums.size() - 1;
        while(R >= 0 && nums[R] == nums[0]) R--;//由于重复元素的出现，可能出现在旋转处出现相同高度的点，导致无法二分
        if (R < 0) return nums[0] == target;//若所有元素都被删去，则首元素为target

        int l = 0, r = R;
        while (l < r)
        {
            //二分出分界点
            int mid = l + r + 1>> 1;
            if(nums[mid] >= nums[0]) l = mid;
            else r = mid - 1;
        }

        if (target >= nums[0])//判断在左右分段
            r = l, l = 0;
        else l ++,r = R;
        
        while (l < r)
        {
            //
            int mid = l + r >> 1;
            if(nums[mid] >= target) r = mid;//继续二分目标
            else l = mid + 1;
        }
        return nums[r] == target;
        
        
    }
};
// @lc code=end

