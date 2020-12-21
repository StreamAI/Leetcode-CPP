/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */

// @lc code=start
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        if(s.empty())
            return -1;
        
        int countChars[26] = {0};
        for(const auto& c : s)
            countChars[c - 'a']++;

        int length = s.length();
        for(int i = 0; i < length; ++i){
            if(countChars[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};
// @lc code=end

