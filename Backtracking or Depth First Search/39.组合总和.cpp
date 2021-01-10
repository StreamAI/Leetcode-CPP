/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> results;

        backTracking(candidates, target, 0, results);

        return results;
    }

    void backTracking(vector<int>& candidates, int target, int index, vector<vector<int>>& results){
        // 使用static 变量用于记录当前选择的组合
        static vector<int> path;
        // 递归遍历的结束条件，若递归到叶子结点或者组合总和满足约束条件则返回
        if(index == candidates.size() || target == 0){
            // 若组合总和正好等于target，则将该组合保存到解空间并返回
            if(target == 0)
                results.push_back(path);
            return;
        }
        //不选择元素candidates[i]，target 不变，索引index 加一
        backTracking(candidates, target, index + 1, results);
        //选择元素candidates[i]，target 减去该元素值，由于可以重复选择该元素，索引index 不变
        if(target - candidates[index] >= 0){
            path.push_back(candidates[index]);
            backTracking(candidates, target - candidates[index], index, results);
            path.pop_back();
        }
    }
/*
    void backTracking(vector<int>& candidates, int target, int index, vector<vector<int>>& results){
        static vector<int> path;
        if(target == 0){
            results.push_back(path);
            return;
        }

        for(int i = index; i < candidates.size(); ++i){
            if(target - candidates[i] < 0)
                continue;

            path.push_back(candidates[i]);
            backTracking(candidates, target - candidates[i], i, results);
            path.pop_back();
        }
    }
*/
};
// @lc code=end

