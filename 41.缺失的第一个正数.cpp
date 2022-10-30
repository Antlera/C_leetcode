/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
class Solution {
public:
    /* int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> hash;
        for(auto x : nums) hash.insert(x);
        int res = 1;
        while (hash.count(res))
            res++;
        return res;
    } */
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();
        for (auto &x : nums)
            if (x != INT_MIN)
                x--;
        for(int i = 0;i < n;i ++){
            while (nums[i] >= 0 && nums[i] < n && nums[i] != i && nums[i] != nums[nums[i]])
            swap(nums[i],nums[nums[i]]);//以本身为索引，归位所有数
        }
        for(int i = 0;i < n;i ++)
            if(nums[i] != i)//若有没有归位的数即为确实的数
                return  i + 1;
        return n + 1;
    }
};
// @lc code=end

