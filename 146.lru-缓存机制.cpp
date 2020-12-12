/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存机制
 */

// @lc code=start
#include<unordered_map>
#include<list>
using namespace std;

class LRUCache {
private:
    unordered_map<int, int> hashtable;
    list<int> listcache;
    int capacity;

public:
    LRUCache(int _capacity): capacity(_capacity){
        
    }
    
    int get(int key) {
        auto iter = hashtable.find(key);
        if(iter == hashtable.end())
            return -1;
        
        listcache.remove(key);
        listcache.push_back(key);
        return iter->second;
    }
    
    void put(int key, int value) {
        auto iter = hashtable.find(key);
        if(iter == hashtable.end()){
            if(listcache.size() < capacity){
                hashtable.insert({key, value});
                listcache.push_back(key);
            }else{
                int lru = listcache.front();
                listcache.pop_front();
                listcache.push_back(key);
                hashtable.erase(lru);
                hashtable.insert({key, value});
            }
        }else{
            hashtable[key] = value;
            listcache.remove(key);
            listcache.push_back(key);
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

