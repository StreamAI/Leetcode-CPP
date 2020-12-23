/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> track;
        vector<bool> used(candidates.size(), false);

        sort(candidates.begin(), candidates.end());
        backTrack(candidates, target, track, 0, used, res);

        return res;
    }

    void backTrack(vector<int>& candidates, int target, vector<int>& track, int begin, vector<bool>& used, vector<vector<int>>& res){
        if(target <= 0){
            if(target == 0)
                res.push_back(track);
            return;
        }

        for(int i = begin; i < candidates.size(); ++i){
            if(target - candidates[i] < 0)
                break;
            if(used[i] == true || (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false))
                continue;

            track.push_back(candidates[i]);
            used[i] = true;
            backTrack(candidates, target - candidates[i], track, i + 1, used, res);
            track.pop_back();
            used[i] = false;
        }
    }
};
// @lc code=end

