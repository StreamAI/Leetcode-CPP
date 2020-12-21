/*
 * @lc app=leetcode.cn id=717 lang=cpp
 *
 * [717] 1比特与2比特字符
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        if(bits.empty())
            return false;

        int i, length = bits.size();
        for(i = 0; i < length - 1; ++i){
            if(bits[i] == 1)
                i++;
        }
        if(i == length - 1)
            return true;
        else
            return false;
    }
};
// @lc code=end

