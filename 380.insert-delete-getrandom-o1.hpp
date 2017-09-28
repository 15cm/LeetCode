class RandomizedSet {
    unordered_map<int, int> valLoc;
    vector<int> locs;
    int sz = 0;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand(time(0));
        locs = vector<int>(10);
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(!valLoc.count(val)) {
            if(sz == locs.size()) locs.resize(sz*2);
            valLoc[val] = sz;
            locs[sz++] = val;
            return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(valLoc.count(val)) {
            int loc = valLoc[val];
            valLoc.erase(val);
            if(loc != sz - 1) {
                locs[loc] = locs[sz-1];
                valLoc[locs[sz-1]] = loc;
            }
            sz--;
            return true;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        if(sz == 0) return -1;
        int loc = rand() % sz;
        return locs[loc];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
