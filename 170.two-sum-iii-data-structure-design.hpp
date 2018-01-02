class TwoSum {
    unordered_map<int, int> mp;
public:
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        mp[number]++;
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for(auto& pr: mp) {
            int k = value - pr.first;
            if(mp.count(k) && (k != pr.first || mp[k] > 1))
                return true;
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */
