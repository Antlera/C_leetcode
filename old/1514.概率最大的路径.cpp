/*
 * @lc app=leetcode.cn id=1514 lang=cpp
 *
 * [1514] 概率最大的路径
 */

// @lc code=start
#include<vector>
#include <queue>
#include<string>
using namespace std;
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<bool> visited(n, false);//初始化点集

        vector<vector<pair<double, int>>> path(n, vector<pair<double, int>>());
        for (int i = 0; i < edges.size(); i++)
        {
            //处理边集，将连线与成功概率绑定
            auto &e = edges[i];
            path[e[0]].push_back({succProb[i], e[1]});
            path[e[1]].push_back({succProb[i], e[0]});
        }
        //优先队列分支限界法
        priority_queue<pair<double, int>> pq;//优先队列按成功率降序排序
        pq.push({1, start});//初始化路径初始值为成功率百分百，以及出发点

        while (!pq.empty())
        {
            //循环查找直至找不到可能的下一个连接点
            auto [curProb, cur] = pq.top();
            pq.pop();//出队最高成功率元素

            if (visited[cur])
                continue;//是否满足限界，当前连接点不在已路径中，
            visited[cur] = true;//更新对应点的访问情况

            if (cur == end)
                return curProb;//访问点到达终点，返回最大概率

            for (auto [nextProb, next] : path[cur])
            {
                //遍历cur对应点的可连边
                if (visited[next])
                    continue; //是否满足限界，下个连接点不在已访问路径中，
                pq.push({curProb * nextProb, next});//加入找到的连接点，更新路径概率，继续搜索
            }
        }

        return 0;//无法找到路径，返回0
    }
};
// @lc code=end

