/*
 * @lc app=leetcode.cn id=74 lang=c
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
#include<stdlib.h>
#include<stdbool.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    if(matrixSize < 1)
        return false;
    if(matrixColSize[0] < 1)
        return false;
    
    int left = 0, right = matrixSize * matrixColSize[0] - 1, mid, pivot;
    while (left <= right)
    {
        mid = left + (right - left)/2;
        pivot = matrix[mid / matrixColSize[0]][mid % matrixColSize[0]];
        if(pivot > target)
            right = mid - 1;
        else if(pivot < target)
            left = mid + 1;
        else
            return true;
    }
    return false;
}
// @lc code=end

