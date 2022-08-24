// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        return binarySearch(matrix, target, 0, 0, matrix.size() - 1, matrix[0].size() - 1);
    }

private:
    bool binarySearch(vector<vector<int>> &matrix, int target, int x_1, int y_1, int x_2, int y_2)
    {
        int m_x = (x_1 + x_2) >> 1;
        int m_y = (y_1 + y_2) >> 1;
        if (matrix[m_x][m_y] == target)
        {
            return true; //若在中心点找到目标找到则直接返回
        }
        else if (matrix[m_x][m_y] > target)
        {
            //目标值小于中心点，在左上/右上/左下三个区域查找
            if (x_1 <= m_x - 1 && binarySearch(matrix, target, x_1, y_1, m_x - 1, y_2))
            {
                //设置条件防止越界
                //在中心点的上部查找
                return true;
            }
            if (m_y - 1 >= y_1 && binarySearch(matrix, target, m_x, 0, x_2, m_y - 1))
            {
                //设置条件防止越界
                //在中心点的左下部查找
                return true;
            }
        }
        else
        {
            //目标值大于中心点，在左上/右下/左下三个区域查找
            if (m_x + 1 <= x_2 && binarySearch(matrix, target, m_x + 1, y_1, x_2, y_2))
            {
                //设置条件防止越界
                //在中心点的下部查找
                return true;
            }
            if (m_y + 1 <= y_2 && binarySearch(matrix, target, x_1, m_y + 1, m_x, y_2))
            {
                //设置条件防止越界
                //在中心点的左上部查找
                return true;
            }
        }
        return false; //找不到目标
    }
};
// @lc code=end

