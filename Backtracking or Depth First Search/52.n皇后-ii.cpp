/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */

// @lc code=start
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        if(n < 1)
            return 0;
        
        vector<string> board(n, string(n, '.'));
        int count = 0;
        backtrack(board, 0, count);

        return count;
    }

    void backtrack(vector<string>& board, int row, int& count){
        if(row == board.size()){
            count++;
            return;
        }

        for(int col = 0; col < board[row].size(); ++col){
            if(isValid(board, row, col) == false)
                continue;
            board[row][col] = 'Q';
            backtrack(board, row + 1, count);
            board[row][col] = '.';
        }
    }

    bool isValid(vector<string>& board, int row, int col){
        // 任何两个皇后都不能处于同一列
        for (int i = 0; i < row; i++){
            if(board[i][col] == 'Q')
                return false;
        }
        // 任何两个皇后都不能处于同一左上右下对角线
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--){
            if(board[i][j] == 'Q')
                return false;
        }
        // 任何两个皇后都不能处于同一左下右上对角线
        for(int i = row - 1, j = col + 1; i >= 0 && j < board.size(); i--, j++){
            if(board[i][j] == 'Q')
                return false;
        }

        return true;
    }
};
// @lc code=end

