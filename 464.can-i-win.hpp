struct pairhash {
    size_t operator() (const pair<int, int> &p) const{
        return (size_t)p.first << 32 | p.second;
    }
};

class Solution {
    unordered_map<pair<int, int>, bool, pairhash> mp;
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int m = maxChoosableInteger, n = desiredTotal;
        if((m+1) * m / 2 < n) return false;
        if(n == 0) return true;
        int choices = 0;
        for(int i = 0, pos = 1; i < m; i++, pos <<= 1) {
            choices |= pos;
        }
        return dfs(choices, n);
    }
    bool dfs(int choices, int n) {
        if(n <= 0) return false;
        pair<int, int> key = {choices, n};
        if(mp.count(key)) return mp[key];
        bool res = false;
        for(int i = 1, pos = 1; i <= 32; i++, pos <<= 1) {
            if(!(choices & pos)) continue;
            if(!dfs(choices ^ pos, n - i)) {
                res = true;
                break;
            }
        }
        return mp[key] = res;
    }
};
