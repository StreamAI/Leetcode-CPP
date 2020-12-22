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
        // 两字符串不等长则false，下面保证了L 和 R 字符的数量与顺序，这里主要保证X 数量相等
        if(sLen != eLen)
            return false;
        // X 相当于空格，L 只能往左移，R 只能往右移
        int i = 0, j = 0;
        while (true) {
            // 跳过X 字符
            while(i < sLen && start[i] == 'X')  i++;
            while(j < eLen && end[j] == 'X')    j++;

            if(i >= sLen || j >= eLen) {
                // 如果一个字符串到末尾了，但另一个未到，说明两个字符串L + R 字符数量不相等
                if(i != j)  return false;
                else    return true;
            } else {
                // 如果start[i] 与end[j] 不相等，或者虽然相等但start L 字符在左或R 字符在右则false(start L 只能左移,R只能右移)
                if(start[i] != end[j] || (start[i] == 'L' && i < j)
                    || (start[i] == 'R' && i > j)) {
                    return false;
                } else {
                    i++;
                    j++;
                }
            }
        }
        
        return true;
/*
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
*/
    }
};
// @lc code=end

