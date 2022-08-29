// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
class Solution {
    private:
        string str;
        int size;
        vector<string> result;
        void dfs(int segment, int index, string cur)
        { // index为字符串str的下标
            if (3 * (4 - segment) < size - index)
                return; //剪枝：如果剩余的都取3个数都不能取完
            if(4-segment>size - index)
                return; //剪枝：剩余的数字不足以组成IP地址
            if (segment == 4 && index == size)
            {
                cur.pop_back(); //处理'.'
                result.emplace_back(cur);//保存结果
                return;
            }
            for (int len = 1; len <= 3 && index + len <= size; len++)
            {
                if (len != 1 && str[index] == '0')
                    continue; //剪枝: 去除含前导0的情况
                if (len == 3 && atoi(str.substr(index, len).c_str()) > 255)
                    continue; //剪枝：去除包含大于255数字的情况
                dfs(segment + 1, index + len, cur + str.substr(index, len) + '.'); //进入下一段匹配，最后一段会多一个'.'
            }
        }

    public:
        vector<string> restoreIpAddresses(string & s)
        {
            str = s;
            size = str.size();
            dfs(0, 0, "");
            return result;
        }

     
};
// @lc code=end

