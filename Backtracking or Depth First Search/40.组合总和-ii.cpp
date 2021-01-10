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
        vector<vector<int>> results;

        sort(candidates.begin(), candidates.end());
        backTracking(candidates, target, 0, results);

        return results;
    }

    void backTracking(vector<int>& candidates, int target, int index, vector<vector<int>>& results){
        // 使用static 变量用于记录当前选择的组合
        static vector<int> path;
        static vector<bool> visited(candidates.size(), false);
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
            if(index > 0 && candidates[index] == candidates[index - 1] && visited[index-1] == false)
                return;
            
            path.push_back(candidates[index]);
            visited[index] = true;
            backTracking(candidates, target - candidates[index], index + 1, results);
            path.pop_back();
            visited[index] = false;
        }
    }

/*
    void backTracking(vector<int>& candidates, int target, int index, vector<vector<int>>& results){
        static vector<int> path;
        static vector<bool> used(candidates.size(), false);
        if(target <= 0){
            if(target == 0)
                results.push_back(path);
            return;
        }

        for(int i = index; i < candidates.size(); ++i){
            if(target - candidates[i] < 0)
                break;
            if(used[i] == true || (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false))
                continue;

            path.push_back(candidates[i]);
            used[i] = true;
            backTracking(candidates, target - candidates[i], i + 1, results);
            path.pop_back();
            used[i] = false;
        }
    }
*/
};
// @lc code=end

