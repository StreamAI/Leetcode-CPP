/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    int fib(int N) {
        if(N <= 0)
            return 0;
        if(N == 1)
            return 1;
        
        int res1 = 0, res2 = 1, temp;
        for(int i = 2; i <= N; i++){
            temp = res1;
            res1 = res2;
            res2 += temp;
        }

        return res2;
    }
};
// @lc code=end

