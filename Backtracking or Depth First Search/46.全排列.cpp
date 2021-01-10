/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {  
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> results;                   

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

