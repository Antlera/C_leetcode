// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(4, 0));
        dp[0][0] = 0;              //不持有股票，收益为0
        dp[0][1] = 0;              //不持有股票，收益为0
        dp[0][2] = -1 * prices[0]; //第1天持有股票，收益为负
        dp[0][3] = -1 * prices[0]; //第1天持有股票，收益为负
        for (int i = 1; i < prices.size(); i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);             //今天不持有股票，但不是今天卖出，前一天不持有股票的两种情况的最大值
            dp[i][1] = max(dp[i - 1][2], dp[i - 1][3]) + prices[i]; //今天卖出股票，来自前一天收益的最大值+price[i]
            dp[i][2] = dp[i - 1][0] - prices[i];                    //今天买入股票，由于冷冻期，前一天一定没有卖出股票
            dp[i][3] = max(dp[i - 1][2], dp[i - 1][3]);             //今天没买股票，却持有股票，前一天继承来的,有两种情况
        }
        return max(dp[prices.size() - 1][0], dp[prices.size() - 1][1]);//收益最大一定是不持有股票状态下
    }
};
// @lc code=end

