/*
 * @lc app=leetcode.cn id=1002 lang=cpp
 *
 * [1002] 查找常用字符
 */

// @lc code=start
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> strFreq(26, 0);
        vector<int> minFreq(26, INT_MAX);
        // strFreq统计每个字符串中每个字符的出现频率
        for(const string& str : A){
            fill(strFreq.begin(), strFreq.end(), 0);
            for(const char& ch : str)
                strFreq[ch - 'a']++;
            // minFreq统计每个字符串中每个字符出现的最小频率，没出现则为0
            for(int i = 0; i < 26; ++i)
                minFreq[i] = min(minFreq[i], strFreq[i]);
        }
        
        vector<string> res;
        for(int i = 0; i < 26; ++i){
            // minFreq[i]为字符 i + 'a' 出现的最小次数
            for(int j = 0; j < minFreq[i]; ++j)
                res.emplace_back(1, i + 'a');
        }

        return res;
    }
};
// @lc code=end

