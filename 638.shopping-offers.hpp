struct v_hash {
    bool operator () (const vector<int> &v) const {
        size_t hash = 0;
        int mask = 0b111;
        for(auto x: v) {
            hash |= x & mask;
            mask <<= 3;
        }
        return hash;
    }
};

class Solution {
    unordered_map<vector<int>, int, v_hash> memo;
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        if(memo.count(needs)) return memo[needs];
        int res = dot(price, needs);
        int n = price.size();
        for(auto &s: special) {
            int i = 0;
            auto tneeds = needs;
            for(; i < n; i++) {
                if(tneeds[i] < s[i]) break;
                tneeds[i] -= s[i];
            }
            if(i < n) continue;
            res = min(res, s.back() + shoppingOffers(price, special, tneeds));
        }
        return memo[needs] = res;
    }
    int dot(vector<int> &lhs, vector<int> &rhs) {
        int sum = 0;
        for(int i = 0; i < lhs.size(); i++)
            sum += lhs[i] * rhs[i];
        return sum;
    }
};
