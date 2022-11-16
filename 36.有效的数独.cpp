/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool st[9];
        for (int i = 0; i < 9; i++)
        {
            memset(st, false, sizeof st);
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    int t = board[i][j] - '1';
                    if (st[t])
                        return false;
                    else
                        st[t] = true;
                }
            }
        }

        for (int i = 0; i < 9; i++)
        {
            memset(st, false, sizeof st);
            for (int j = 0; j < 9; j++)
            {
                if (board[j][i] != '.')
                {
                    int t = board[j][i] - '1';
                    if (st[t])
                        return false;
                    else
                        st[t] = true;
                }
            }
        }

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                int a = 3 * i, b = 3 * j;
                memset(st, false, sizeof st);
                for (int x = 0; x < 3; x++)
                    for (int y = 0; y < 3; y++)
                    {
                        if (board[a + x][b + y] != '.')
                        {
                            int t = board[a + x][b + y] - '1';
                            if (st[t])
                                return false;
                            else
                                st[t] = true;
                        }
                    }
            }
        }
        return true;
    }
};
// @lc code=end

