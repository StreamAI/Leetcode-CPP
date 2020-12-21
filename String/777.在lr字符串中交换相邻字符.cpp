/*
 * @lc app=leetcode.cn id=777 lang=cpp
 *
 * [777] 在LR字符串中交换相邻字符
 */

// @lc code=start
#include<string>
using namespace std;

class Solution {
public:
    bool canTransform(string start, string end) {
        int sLen = start.length();
        int eLen = end.length();
        string ts = start, te = end;
        int ps = ts.find("X"), pe = te.find("X");
        while (ps != string::npos || pe != string::npos) {
            if(ps != string::npos){
                ts.replace(ps, 1, "");
                ps = ts.find("X");
            }
            if(pe != string::npos){
                te.replace(pe, 1, "");
                pe = te.find("X");
            }
        }
        if(ts != te)
            return false;

        for(int i = 0, j = 0; i < sLen; ++i){
            if(start[i] == 'L'){
                while (end[j] != 'L')
                    j++;
                if(i < j)
                    return false;
                else
                    j++;
            }
        }

        for(int i = 0, j = 0; i < sLen; ++i){
            if(start[i] == 'R'){
                while (end[j] != 'R')
                    j++;
                if(i > j)
                    return false;
                else
                    j++;
            }
        }

        return true;
    }
};
// @lc code=end

