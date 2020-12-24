/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
private:
    unordered_map<char, string> phoneMap = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, 
            {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.empty())
            return res;
        string track;
        backTrack(digits, track, 0, res);
        return res;
    }

    void backTrack(string& digits, string& track, int index, vector<string>& res){
        if(track.length() == digits.length()){
            res.push_back(track);
            return;
        }

        char dig = digits[index];
        string str = phoneMap[dig];
        for(int i = 0; i < str.length(); ++i){
            track.push_back(str[i]);
            backTrack(digits, track, index + 1, res);
            track.pop_back();
        }
    }
};
// @lc code=end

