/*
 * @lc app=leetcode.cn id=424 lang=cpp
 *
 * [424] 替换后的最长重复字符
 */

// @lc code=start
#include<string>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        if(s.empty() || k < 0)
            return 0;

        int countChars[26] = {0};
        int maxlen = 0, maxChar = 0, length = s.length();
        int left = 0, right = 0;
        while (right < length) {
            int in = s.at(right) - 'A';
            right++;
            countChars[in]++;
            maxChar = max(maxChar, countChars[in]);
            if(right - left - maxChar > k){
                int out = s.at(left) - 'A';
                left++;
                countChars[out]--;
            }
            maxlen = max(maxlen, right - left);
        }
        return maxlen;
    }
};
// @lc code=end

