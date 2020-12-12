/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowSize = matrix.size();
        if(rowSize < 1) return false;
        int colSize = matrix[0].size();
        if(colSize < 1) return false;

        for (int i = 0; i < rowSize; i++)
        {
            if(target < matrix[i][0] || target > matrix[i][colSize-1])
                continue;
            int left = 0, right = colSize - 1, mid, pivot;
            while (left <= right)
            {
                mid = left + (right - left)/2;
                pivot = matrix[i][mid];
                if(pivot < target)
                    left = mid + 1;
                else if(pivot > target)
                    right = mid - 1;
                else
                    return true;
            }  
        }
        return false;
    }
};
// @lc code=end

