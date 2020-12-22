/*
 * @lc app=leetcode.cn id=828 lang=cpp
 *
 * [828] 统计子串中的唯一字符
 */

// @lc code=start
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int uniqueLetterString(string s) {
        int length = s.length();
        if(length < 1)
            return 0;
        // left[length] 记录每个字符只出现一次的区间的左边界，prev[26] 用于辅助记录每种字符上次出现的位置
        vector<int> left(length, 0);
        vector<int> prev(26, -1);
        for(int i = 0; i < length; ++i){
            left[i] = prev[s[i] - 'A'];
            prev[s[i] - 'A'] = i;
        }
        // right[length] 记录每个字符只出现一次的区间的右边界，prev[26] 用于辅助记录每种字符上次出现的位置
        vector<int> right(length, 0);
        fill(prev.begin(), prev.end(), length);
        for(int j = length - 1; j >= 0; --j){
            right[j] = prev[s[j] - 'A'];
            prev[s[j] - 'A'] = j;
        }
        // 每个字符只出现一次的区间[left[i] + 1, right[i] - 1] 内该字符作为唯一字符的子串个数为(i - left[i]) * (right[i] - i)
        size_t res = 0;
        for(int i = 0; i < length; ++i)
            res += (i - left[i]) * (right[i] - i);

        return  (int)(res % (size_t)(1e9 + 7));
    }
};
// @lc code=end

