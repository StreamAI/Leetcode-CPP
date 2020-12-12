/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
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

        int left = 0, right = rowSize * colSize - 1, mid, pivot;
        while (left <= right)
        {
            mid = left + (right - left)/2;
            pivot = matrix[mid / colSize][mid % colSize];
            if(pivot > target)
                right = mid - 1;
            else if(pivot < target)
                left = mid + 1;
            else
                return true;  
        }
        return false;
    }
};
// @lc code=end

