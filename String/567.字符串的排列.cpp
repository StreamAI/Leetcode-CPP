/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

// @lc code=start
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() < 1 || s2.size() < s1.size())
            return false;

        unordered_map<char, int> need, window;
        for(const auto& c : s1)
            need[c]++;

        int left = 0, right = 0, match_count = 0;
        while (right < s2.size())
        {
            char in = s2[right];
            right++;

            if(need.find(in) != need.end()){
                window[in]++;
                if(window[in] == need[in])
                    match_count++;
            }

            while(match_count == need.size())
            {
                if(right - left == s1.size())
                    return true;
                
                char out = s2[left];
                left++;

                if(need.find(out) != need.end()){
                    if(window[out] == need[out])
                        match_count--;
                    window[out]--;
                }
            }
        }

        return false;
    }
};
// @lc code=end

