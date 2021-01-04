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
        if(len1 == 0 || len2 == 0)
            return len1 + len2;

        vector<vector<int>> dp(len1+1, vector<int>(len2+1, INT_MAX));
        for(int s1 = 0; s1 <= len1; ++s1)
            dp[s1][0] = s1;
        for(int s2 = 0; s2 <= len2; ++s2)
            dp[0][s2] = s2;

        for(int s1 = 1; s1 <= len1; ++s1){
            for(int s2 = 1; s2 <= len2; ++s2){
                if(word1[s1-1] == word2[s2-1])
                    dp[s1][s2] = dp[s1-1][s2-1];
                else{
                    int rep = dp[s1-1][s2-1] + 1;
                    int ins = dp[s1][s2-1] + 1;
                    int del = dp[s1-1][s2] + 1;
                    dp[s1][s2] = min(rep, min(ins, del));
                }
            }
        }
        return dp[len1][len2];
    }
};
// @lc code=end

