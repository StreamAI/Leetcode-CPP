/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> results;

        sort(nums.begin(), nums.end());
        backTracking(nums, results);

        return results;
    }

    void backTracking(vector<int>& nums, vector<vector<int>>& results){
	    // 使用static 变量只在第一次定义并初始化，后续递归调用不会再重新定义或初始化，用于记录选择路径、标记已选择元素
        static vector<int> path;
        static vector<bool> visited(nums.size(), false);
        // 递归遍历的结束条件，若满足结束条件则将该排列放入解空间并返回
        if(path.size() == nums.size()){
            results.push_back(path);
            return;
        }
        // 每个结点状态逐个遍历可能的选择分支
        for (int i = 0; i < nums.size(); ++i) {
            // 跳过前面已选择的分支，也即剪枝，提高效率
            if(visited[i] == true)
                continue;
            // 若元素nums[i] 与nums[i-1] 相等，且nums[i-1] 已取消标记，再重新选择重复元素nums[i] 将会获得重复排列，应跳过该选择
            if(i > 0 && nums[i] == nums[i-1] && visited[i-1] == false)
                continue;
            // 将分支nums[i] 添加到当前选择路径，并标记该元素已选择
            path.push_back(nums[i]);
            visited[i] = true;
            // 按照DFS 遍历规律，沿当前选择路径继续向下一阶段递归
            backTracking(nums, results);
            // 回退到上一阶段并将分支nums[i] 从当前选择路径移除，取消该元素的标记
            path.pop_back();
            visited[i] = false;
        }
    }
};
// @lc code=end

