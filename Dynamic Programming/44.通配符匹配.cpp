/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 */

// @lc code=start
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int sLen = s.length();
        int pLen = p.length();
        
        vector<vector<bool>> dp(sLen+1, vector<bool>(pLen+1, false));

        for(int j = 0; j <= pLen; j++){
            if(j == 0 || p[j-1] == '*')
                dp[0][j] = true;
            else
                break;
        }

        for(int i = 1; i <= sLen; i++){
            for(int j = 1; j <= pLen; j++){
                if(p[j-1] == '?' || s[i-1] == p[j-1])
                    dp[i][j] = dp[i-1][j-1];
                if(p[j-1] == '*'){
                    dp[i][j] = dp[i][j-1] | dp[i-1][j];
                }
            }
        }
        
        return dp[sLen][pLen];
        /*
        bool matched = false;
        dfs(s, sLen, p, pLen, matched);
        return matched;
        */
    }
/*
    void dfs(string s, int i, string p, int j, bool& matched){
        if(j == 0){
            if(i == 0)
                matched = true;
            return;
        }

        if(p[j-1] == '*'){
            for(int k = 0; k <= i; k++)
                dfs(s, i-k, p, j-1, matched);
        }else if(p[j-1] == '?')
            dfs(s, i-1, p, j-1, matched);
        else if(i > 0 && s[i-1] == p[j-1])
            dfs(s, i-1, p, j-1, matched);
    }
*/
};
// @lc code=end

