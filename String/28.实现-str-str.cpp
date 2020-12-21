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
        int hLen = haystack.length();
        int nLen = needle.length();
        if(haystack.empty() || hLen < nLen)
            return -1;

        int si = 0, ti = 0;
        while (si < hLen && ti < nLen)
        {
            if(haystack[si] == needle[ti]){
                si++;
                ti++;
            } else {
                si -= ti - 1;
                ti = 0;
            }
        }
        
        if(ti == nLen)
            return si - ti;
        else
            return -1;
    }
};
// @lc code=end

