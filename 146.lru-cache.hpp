#define MAXN 65536
#include <vector>
#include <list>
using namespace std;
class LRUCache {
public:
    vector<pair<int, list<int>::iterator>> cache;
    list<int> lru;
    int size, capacity;
    pair<int, list<int>::iterator> default_pair;
    LRUCache(int capacity) {
        size = 0;
        this->capacity = capacity;
        default_pair = decltype(default_pair)(-1, list<int>::iterator());
        cache = decltype(cache)(MAXN, default_pair);
    }
    
    int get(int key) {
        if(key >= cache.size()) {
            cache.resize(key - cache.size() + key, default_pair);
        }
        auto& p = cache[key];
        if(p.first != -1) {
            lru.erase(p.second);
            lru.push_front(key);
            p.second = lru.begin();
            return p.first;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(key >= cache.size()) {
            cache.resize(key - cache.size() + key, default_pair);
        }
        auto& p = cache[key];
        if(p.first != -1) {
            lru.erase(p.second);
        } else {
            if(size == capacity) {
                cache[lru.back()].first = -1;
                lru.pop_back();
            } else {
                size++;
            }
        }
        lru.push_front(key);
        p.first = value;
        p.second = lru.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
