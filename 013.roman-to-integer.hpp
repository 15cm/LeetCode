class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int last = 0;
        int ans = 0;
        for(auto it = s.rbegin(); it != s.rend(); ++it) {
            auto c = *it;
            if(mp.count(c)) {
                if(last != 0 && mp[c] < last) {
                    ans -= mp[c];
                    last = 0;
                } else {
                    ans += mp[c];
                    last = mp[c];
                }
            } else {
                last = 0;
            }
        }
        return ans;
    }
};
