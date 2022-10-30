/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int k = nums.size() - 1;
        while(k && nums[k - 1] >= nums[k])k --;//找到一个非降序的
        if(k <= 0)reverse(nums.begin(),nums.end());//若全为降序，则直接反转转为升序
        else{
            int t = k;
            while (t < nums.size() && nums[t] > nums[k - 1])t++;//找到最小的大于该数的数，进行调换，保持之后的降序，直接进行反转即可
            swap(nums[t - 1], nums[k - 1]);
            reverse(nums.begin()+k,nums.end());
        }
    }
};
// @lc code=end

