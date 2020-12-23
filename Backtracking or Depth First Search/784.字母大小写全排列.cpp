/*
 * @lc app=leetcode.cn id=784 lang=cpp
 *
 * [784] 字母大小写全排列
 */

// @lc code=start
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;

        dfs(S, 0, res);
        
        return res;
    }

    void dfs(string& str, int index, vector<string>& res){
        if(index == str.length()){
            res.push_back(str);
            return;
        }
        // str[index]不转换大小写
        dfs(str, index + 1, res);
        // str[index]若为字母则大小写转换
        if(isalpha(str[index])){
            isupper(str[index]) ? str[index] = tolower(str[index]) : str[index] = toupper(str[index]);
            dfs(str, index + 1, res);
        }
    }
};
// @lc code=end

