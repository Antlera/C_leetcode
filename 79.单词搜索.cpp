/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0;i < board.size();i++){
            for(int j = 0;j < board[i].size();j++){
                if(dfs(board,word,0,i,j))return true;//遍历棋盘的每一个格子，dfs
            }
        }
        return false;
    }
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    bool dfs(vector<vector<char>>& board,string& word,int u,int x,int y){
        if(board[x][y] != word[u]) return false;//若当前期盼不符合word的第u个字，则返回false
        if(u == word.size() - 1) return true;//若u达到最后一位返回true

        char t = board[x][y];
        board[x][y] = '.';//处理当前棋盘格为使用过
        for(int i = 0;i < 4;i ++){
            int a = x + dx[i], b = y + dy[i];
            if(a < 0 || a >= board.size() || b < 0 || b >= board[0].size() || board[a][b] == '.') continue;//若当前格子越界或使用过则跳过
            if(dfs(board,word,u+1,a,b))return true;//继续搜索下一位
        }
        board[x][y] = t;
        return false;
    }

};
// @lc code=end

