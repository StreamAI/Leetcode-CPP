/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> results;
        backTracking(nums, 0, results);
        return results;
    }

    void backTracking(vector<int>& nums, int index, vector<vector<int>>& results)
    {
        // 使用static 变量只在第一次定义并初始化，后续递归调用不会再重新定义或初始化，用于记录选择路径
        static vector<int> path;
        // 递归遍历的结束条件，若递归到叶子结点则将该组合放入解空间并返回
        if(index == nums.size()){
            results.push_back(path);
            return;
        }
        // 选择当前元素nums[index]
        path.push_back(nums[index]);
        backTracking(nums, index + 1, results);
        path.pop_back();
        // 不选择当前元素nums[index]
        backTracking(nums, index + 1, results);
    }
/*
    void backTracking(vector<int>& nums, int index, vector<vector<int>>& results)
    {
        // 使用static 变量只在第一次定义并初始化，后续递归调用不会再重新定义或初始化，用于记录选择路径
        static vector<int> path;
        // 递归遍历所有结点，并将该组合放入解空间
        results.push_back(path);
        // 每个结点状态逐个遍历可能的选择分支，变量 i 初始值为index，且在每次递归增加 1，保证只选择后续分支
        for(int i = index; i < nums.size(); ++i){
            // 将分支nums[i] 添加到当前选择路径
            path.push_back(nums[i]);
            // 按照DFS 遍历规律，沿当前选择路径继续向下一阶段递归，变量 i+1 保证后续只选择分支nums[i] 后面的元素
            backTracking(nums, i + 1, results);
            // 回退到上一阶段并将分支nums[i] 从当前选择路径移除
            path.pop_back();
        }
    }
*/
};
// @lc code=end

