/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
#include<string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty())  return 0;
        if(haystack.empty() || haystack.size() < needle.size())
            return -1;

        int si = 0, ti = 0;
        while (si < haystack.length() && ti < needle.length())
        {
            if(haystack[si] == needle[ti]){
                si++;
                ti++;
            } else {
                si -= ti - 1;
                ti = 0;
            }
        }
        
        if(ti == needle.length())
            return si - ti;
        else
            return -1;
    }
};
// @lc code=end

