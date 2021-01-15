/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        
        // 创建状态转移表
        int dp[len1 + 1][len2 + 1];
        // 初始化状态转移表，也即其中一个字符串为空时的情况
        for(int i = 0; i <= len1; ++i)
            dp[i][0] = i;
        for(int j = 0; j <= len2; ++j)
            dp[0][j] = j;
        // 按照状态转移方程从初始状态往后依次填表
        for(int i = 1; i <= len1; ++i){
            for(int j = 1; j <= len2; ++j){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i - 1][j - 1];
                }else{
                    int ins = dp[i][j - 1] + 1;
                    int del = dp[i - 1][j] + 1;
                    int rep = dp[i - 1][j - 1] + 1;
                    dp[i][j] = min(rep, min(ins, del));
                }
            }
        }
        
        //vector<vector<int>> memo(len1+1, vector<int>(len2+1, INT_MAX));
        //dp_memo(word1, len1, word2, len2, memo);

        return dp[len1][len2];
    }
    /*
    int dp_memo(string word1, int i, string word2, int j, vector<vector<int>>& memo){
        if(i == 0 || j == 0){
            return i + j;
        }

        if(memo[i][j] < INT_MAX)
            return memo[i][j];
        else{
            if(word1[i - 1] == word2[j - 1]){
                memo[i][j] = dp_memo(word1, i - 1, word2, j - 1, memo);
                return memo[i][j];
            } else {
                int rep = dp_memo(word1, i - 1, word2, j - 1, memo) + 1;
                int ins = dp_memo(word1, i, word2, j - 1, memo) + 1;
                int del = dp_memo(word1, i - 1, word2, j, memo) + 1;
                memo[i][j] = min(rep, min(ins, del));
                return memo[i][j];
            }
        }
    }
    */
};
// @lc code=end

