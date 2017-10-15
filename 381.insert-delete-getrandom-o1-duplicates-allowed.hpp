class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    unordered_map<int, unordered_set<int>> mp;
    vector<int> arr;
    int sz = 0;
    RandomizedCollection() {
        arr = vector<int>(10);
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        if(sz == arr.size()) {
            resize(sz * 2);
        }
        mp[val].insert(sz);
        arr[sz++] = val;
        return mp[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(mp[val].size() > 0) {
            int idx = *mp[val].begin();
            mp[val].erase(idx);
            if(idx == sz - 1) {
                sz--;
            } else {
                int ele = arr[--sz];
                swap(arr[idx], arr[sz]);
                mp[ele].erase(sz);
                mp[ele].insert(idx);
            }
            return true;
        } else {
            return false;
        }
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return arr[rand() % sz];
    }
private:
    void resize(int newSz) {
        arr.resize(newSz);
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
