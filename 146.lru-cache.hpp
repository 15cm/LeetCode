typedef list<int> LI;
typedef LI::iterator LIIT;
class LRUCache {
public:
    unordered_map<int, pair<int, LIIT>> mp;
    LI cache;
    int capacity;
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(!mp.count(key)) return -1;
        touch(key);
        return mp[key].first;
    }
    
    void put(int key, int value) {
        if(mp.count(key)) {
            touch(key);
            mp[key].first = value;
        } else {
            cache.push_back(key);
            mp[key] = make_pair(value, prev(cache.end()));
            checkCache();
        }
    }
private:
    void touch(int key) {
        cache.erase(mp[key].second);
        cache.push_back(key);
        mp[key].second = prev(cache.end());
    }
    void checkCache() {
        if(cache.size() > capacity) {
            mp.erase(*cache.begin());
            cache.pop_front();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
