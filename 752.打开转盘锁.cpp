/*
 * @lc app=leetcode.cn id=752 lang=cpp
 *
 * [752] 打开转盘锁
 */

// @lc code=start
#include<vector>
#include<string>
#include<queue>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<string> bfs;
        unordered_set<string> visited;
        unordered_set<string> deads;
        for(const auto& str : deadends)
            deads.insert(str);
        
        unsigned int step = 0;
        string init = "0000";
        bfs.push(init);
        visited.insert(init);

        while (!bfs.empty())
        {
            int layer_count = bfs.size();

            while (layer_count--)
            {
                string current = bfs.front();
                bfs.pop();

                if(deads.find(current) != deads.end())
                    continue;
                if(current == target)
                    return step;

                for(int i = 0; i < 4; i++){
                    string up = plusone(current, i);
                    if(visited.find(up) == visited.end()){
                        bfs.push(up);
                        visited.insert(up);
                    }
                    string down = minusone(current, i);
                    if(visited.find(down) == visited.end()){
                        bfs.push(down);
                        visited.insert(down);
                    }
                }
            }
            step++;
        }
        return -1;
    }

    string plusone(string str, int i){
        if(str[i] == '9')
            str[i] = '0';
        else
            str[i]++;

        return str;
    }

    string minusone(string str, int i){
        if(str[i] == '0')
            str[i] = '9';
        else
            str[i]--;

        return str;
    }
};
// @lc code=end

