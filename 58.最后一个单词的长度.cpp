/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
class Solution{
public:
    /*  int lengthOfLastWord(string s) {
            stringstream ssin(s);
            string word;
            while (ssin >> word);
            return word.size();
        } */
    /*     int lengthOfLastWord(string s)
        {
            for(int i = s.size()-1;i >= 0;i--){
                if(s[i]==' ')continue;
                int j = i - 1;
                while (j >= 0 && s[j] != ' ') j--;
                return i - j;
            }
            return 0;
        } */
    int lengthOfLastWord(string s)
    {
        int res = 0;
        for(int i = 0;i < s.size();i++){
            if(s[i]==' ')continue;
            int j = i;
            while (j < s.size() && s[j] != ' ') j++;
            res = j - i;
            i = j;
        }
        return res;
    }

}; // @lc code=end
