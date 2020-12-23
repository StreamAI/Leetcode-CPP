/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> track;

        backTrack(k, n, track, 1, res);

        return res;
    }

    void backTrack(int k, int n, vector<int>& track, int begin, vector<vector<int>>& res){
        if(n <= 0 || k <= 0){
            if(n == 0 && k == 0)
                res.push_back(track);
            return;
        }

        for(int i = begin; i <= 9; ++i){
            if(n - i < 0)
                break;
            
            track.push_back(i);
            backTrack(k - 1, n - i, track, i + 1, res);
            track.pop_back();
        }
    }
};
// @lc code=end

