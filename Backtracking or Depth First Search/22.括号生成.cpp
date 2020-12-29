/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string track;
        backTrack(n, 0, 0, track, res);
        return res;
    }

    void backTrack(int n, int left, int right, string& track, vector<string>& res){
        // left 为左括号数量，right 为右括号数量，匹配的括号组合任一前缀子串满足left >= right
        if(track.length() == 2 * n){
            res.push_back(track);
            return;
        }

        if(left < n){
            track.push_back('(');
            backTrack(n, left + 1, right, track, res);
            track.pop_back();
        }
        
        if(right < left){
            track.push_back(')');
            backTrack(n, left, right + 1, track, res);
            track.pop_back();
        }
    }
};
// @lc code=end

