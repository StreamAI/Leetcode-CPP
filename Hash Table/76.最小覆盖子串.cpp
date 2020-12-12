/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() < 1 || s.size() < t.size())
            return "";

        unordered_map<char, int> need, window;
        for(const auto& c : t)
            need[c]++;

        int left = 0, right = 0;
        int match_count = 0;
        int start = 0, len = INT_MAX;
        while (right < s.size())
        {
            char in = s[right];
            right++;

            if(need.find(in) != need.end()){
                window[in]++;
                if(window[in] == need[in])
                    match_count++;
            }

            while (match_count == need.size())
            {
                if(right - left < len){
                    start = left;
                    len = right - left;
                }

                char out = s[left];
                left++;

                if(need.find(out) != need.end()){
                    if(window[out] == need[out])
                        match_count--;
                    window[out]--;
                }
            }    
        }
        return (len == INT_MAX) ? "" : s.substr(start, len);
    }
};
// @lc code=end

