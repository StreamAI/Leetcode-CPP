/*
 * @lc app=leetcode.cn id=442 lang=cpp
 *
 * [442] 数组中重复的数据
 */

// @lc code=start
#include<vector>
using namespace std;


class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int size = 0;
        vector<int> res(nums.size()+1, 0);

        for(auto iter = nums.begin(); iter != nums.end(); ++iter)
            res[(*iter)]++;

        for(int i = 0; i <= nums.size(); ++i){
            if(res[i] == 2)
                res[size++] = i;
        }

        res.resize(size);
        return res;
    }
};
// @lc code=end

