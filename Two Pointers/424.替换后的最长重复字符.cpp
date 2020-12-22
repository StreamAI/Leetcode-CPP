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
            // 存储[left, right]区间内出现次数最多的字符的出现次数
            maxChar = max(maxChar, countChars[in]);
            // right - left - maxChar 为区间[left, right]内使所有字符相同至少需要的替换次数
            if(right - left - maxChar > k){
                int out = s.at(left) - 'A';
                left++;
                countChars[out]--;
            }
            // 替换k 个字符使区间[left, right]内所有字符相同的最大区间长度
            maxlen = max(maxlen, right - left);
        }
        return maxlen;
    }
};
// @lc code=end

