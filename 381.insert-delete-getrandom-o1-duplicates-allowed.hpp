class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    unordered_map<int, unordered_set<int>> mp;
    vector<int> arr;
    RandomizedCollection() {
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        mp[val].insert(arr.size());
        arr.push_back(val);
        return mp[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(mp[val].size() > 0) {
            int idx = *mp[val].begin();
            mp[val].erase(idx);
            if(idx == arr.size() - 1) {
                arr.pop_back();
            } else {
                int ele = arr.back();
                swap(arr[idx], arr.back());
                arr.pop_back();
                mp[ele].erase(arr.size());
                mp[ele].insert(idx);
            }
            return true;
        } else {
            return false;
        }
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return arr[rand() % arr.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
