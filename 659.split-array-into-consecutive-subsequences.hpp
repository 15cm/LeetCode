class Counter {
    unordered_map<int, int> mp;
public:
    void add(int key, int val) {
        mp[key] += val;
    }
    int get(int key) {
        return mp.count(key) ? mp[key] : 0;
    }
};

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        Counter cnt, tails;
        for(int x: nums) cnt.add(x, 1);
        for(int x: nums) {
            if(cnt.get(x) == 0) continue;
            else if(tails.get(x) > 0) {
                tails.add(x, -1);
                tails.add(x + 1, 1);
            } else if(cnt.get(x + 1) > 0 && cnt.get(x + 2) > 0) {
                cnt.add(x + 1, -1);
                cnt.add(x + 2, -1);
                tails.add(x + 3, 1);
            } else {
                return false;
            }
            cnt.add(x, -1);
        }
        return true;
    }
};
