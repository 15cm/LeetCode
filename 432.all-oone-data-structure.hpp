class AllOne {
    unordered_map<string, int> mp;
    vector<unordered_set<string>> grp;
    int head, tail;
public:
    /** Initialize your data structure here. */
    AllOne() {
        head = tail = 0;
        grp = vector<unordered_set<string>>(10, unordered_set<string>());
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        int val = 1;
        if(mp.count(key)) {
            val = mp[key];
            grp[val].erase(key);
            val++;
        }
        mp[key] = val;
        if(val == grp.size()) {
            grp.resize(grp.size() * 2);
        }
        grp[val].insert(key);
        if(val > tail) {
            tail = val;
        }
        if(val < head) {
            head = val;
        }
        if(grp[head].empty()) {
            head++;
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if(!mp.count(key)) return;
        int val = mp[key];
        grp[val].erase(key);
        val--;
        if(val == 0) {
            mp.erase(key);
            while(head < tail && grp[head].empty()) {
                head++;
            }
        } else {
            mp[key] = val;
            grp[val].insert(key);
            if(val < head) {
                head = val;
            }
        }
        if(grp[tail].empty()) {
            tail--;
        }
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if(tail > 0) {
            return *grp[tail].begin();
        }
        else
            return "";
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if(head > 0)
            return *grp[head].begin();
        else
            return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */
