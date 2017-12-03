#include <unordered_map>
#include <list>
using namespace std;
class LFUCache {
    unordered_map<int, int> kv;
    unordered_map<int, pair<list<pair<int, list<int>>>::iterator, list<int>::iterator>> kIter;
    list<pair<int, list<int>>> freq;
    int cap;
public:
    LFUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(!kv.count(key)) return -1;
        touch(key);
        return kv[key];
    }
    
    void put(int key, int value) {
        if(cap == 0) return;
        if(kv.count(key)) {
            kv[key] = value;
        } else {
            if(kv.size() < cap) {
                kv[key] = value;
            } else {
                removeOne();
                kv[key] = value;
            }
            freq.push_front(make_pair(0, list<int> {key}));
            kIter[key] = make_pair(freq.begin(), freq.begin()->second.begin());
        }
        touch(key);
    }

    void touch(int key) {
        auto& pr = kIter[key];
        auto it = pr.first;
        auto after = next(it);
        it->second.erase(pr.second);
        list<pair<int, list<int>>>::iterator cur;
        if(after != freq.end() && it->first + 1 == after->first) {
            after->second.push_back(key);
            cur = after;
        } else {
            cur = freq.insert(after, make_pair(it->first + 1, list<int>{key}));
        }
        kIter[key].first = cur;
        kIter[key].second = prev(cur->second.end());
        if(it->second.empty()) freq.erase(it);
    }

    void removeOne() {
        auto it = freq.begin();
        int key = *it->second.begin();
        it->second.pop_front();
        if(it->second.empty()) {
            freq.erase(it);
        }
        kv.erase(key);
        kIter.erase(key);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
