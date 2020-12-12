/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
#include<vector>
#include<string>
using namespace std;

class Solution {
private:
    vector<vector<string>> res;

public:
    vector<vector<string>> solveNQueens(int n) {
        res.clear();
        if(n < 1)
            return res;
        
        vector<string> board(n, string(n, '.'));
        backtrack(board, 0);

        return res;
    }

    void backtrack(vector<string>& board, int row){
        if(row == board.size()){
            res.push_back(board);
            return;
        }

        for(int col = 0; col < board[row].size(); ++col){
            if(isValid(board, row, col) == false)
                continue;
            board[row][col] = 'Q';
            backtrack(board, row + 1);
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

