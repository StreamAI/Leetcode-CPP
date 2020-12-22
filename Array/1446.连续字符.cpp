/*
 * @lc app=leetcode.cn id=1446 lang=cpp
 *
 * [1446] 连续字符
 */

// @lc code=start
#include<string>
using namespace std;

class Solution {
public:
    int maxPower(string s) {
        int length = s.length();
        if(length < 2)
            return length;
        
        int countChar = 1, maxCount = 0;
        for(int i = 1; i < length; ++i){
            if(s[i] == s[i - 1])
                countChar++;
            else{
                maxCount = max(maxCount, countChar);
                countChar = 1;
            }
        }
        maxCount = max(maxCount, countChar);
        
        return maxCount;
    }
};
// @lc code=end

