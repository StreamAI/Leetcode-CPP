/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = s.length();
        if(length < 2)
            return length;

        unordered_map<char, int> hashChar;
        int left = 0, right = 0, len = 0, maxlen = 0;
        while (right < length) {
            char in = s[right];
            right++;
            hashChar[in]++;
            len++;
            while(hashChar[in] > 1){
                maxlen = max(maxlen, len - 1);
                char out = s[left];
                left++;
                hashChar[out]--;
                len--;
            }
        }
        maxlen = max(maxlen, len);

        return maxlen;
    }
};
// @lc code=end

