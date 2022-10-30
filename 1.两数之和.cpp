/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
/*     vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> h;//利用hash表，若能找到target-nums[i]则返回，若找不到则继续插入
        for (int i = 0; i < nums.size(); i++)
        {
            int r = target - nums[i];
            if(h.count(r)) return {h[r],i};
            h[nums[i]] = i;
        }
        return {}; 
    } */
    // vector<int> twoSum(vector<int> &nums, int target)//坐标固定无法使用排序双指针
    // {
    //     sort(nums.begin(),nums.end());
    //     for (int i = 0,j = nums.size() - 1; i < j; i++)
    //     {
    //         while (i < j - 1 && nums[i] + nums[j] >= target)j--;
    //         if (nums[i] + nums[j] == target)
    //             return {i, j};
    //     }
    //     return {};
    // }
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++)
        {
            int r = target - nums[i]; //计算配对数
            if (hash[r])
                return {hash[r] - 1, i};
            else
                hash[nums[i]] = i + 1;
        }
        return {};
    }
};
// @lc code=end

