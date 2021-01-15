/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.length();
        int len2 = text2.length();
        
        int dp[len1+1][len2+1];

        for(int i = 0; i <= len1; ++i)
            dp[i][0] = 0;
        for(int j = 0; j <= len2; ++j)
            dp[0][j] = 0;
        
        for(int i = 1; i <= len1; ++i){
            for(int j = 1; j <= len2; ++j){
                if(text1[i-1] == text2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
        
        //vector<vector<int>> memo(len1+1, vector<int>(len2+1, INT_MIN));
        //dp_memo(text1, len1, text2, len2, memo);
        return dp[len1][len2];
    }
    /*
    int dp_memo(string text1, int i, string text2, int j, vector<vector<int>>& memo){
        if(i == 0 || j == 0)
            return 0;

        if(memo[i][j] > INT_MIN)
            return memo[i][j];
        else{
            if(text1[i-1] == text2[j-1]){
                memo[i][j] = dp_memo(text1, i - 1, text2, j - 1, memo) + 1;
                return memo[i][j];
            } else {
                int ins = dp_memo(text1, i, text2, j - 1, memo);
                int del = dp_memo(text1, i - 1, text2, j, memo);
                memo[i][j] = max(ins, del);
                return memo[i][j];
            }
        }
    }
    */
};
// @lc code=end

