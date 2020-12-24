/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start 
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> track;
        backTrack(n, k, track, 1, res);
        return res;
    }

    void backTrack(int n, int k, vector<int>& track, int index, vector<vector<int>>& res) {
        if(k == 0){
            res.push_back(track);
            return;
        }

        for(int i = index; i <= n; ++i){
            track.push_back(i);
            backTrack(n, k - 1, track, i + 1, res);
            track.pop_back();
        }
    }
};
// @lc code=end

