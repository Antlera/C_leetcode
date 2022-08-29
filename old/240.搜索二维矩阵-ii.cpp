// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
        {
            return false;
        }
        for (int i = 0; i < matrix.size(); i++)
        {
            if (matrix[i][0] > target)
            {
                break;
            }
            if (matrix[i][matrix[i].size() - 1] < target)
            {
                continue;
            }
            int col = binarySearch(matrix[i], target);
            if (col != -1)
            {
                return true;
            }
        }
        return false;
    }
    //二分查找
private:
    int binarySearch(vector<int> &nums, int target)
    {
        int start = 0;
        int end = nums.size() - 1;
        while (start <= end)
        {
            int mid = (start + end) >> 1;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return -1;
    }
};
// @lc code=end

