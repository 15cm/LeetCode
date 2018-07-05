
class Solution {
public:
    int minSteps(int n) {
        if(n == 1) return 0;
        pair<int, int> src = {1, 0};
        vector<pair<int, int>> lvl, tlvl;
        vector<vector<bool>> memo(n, vector<bool>(n));
        lvl.push_back(src);
        int k = 0;
        while(true) {
            k++;
            tlvl.clear();
            for(auto &pr: lvl) {
                int cur, paste;
                for(int i = 0; i < 2; i++) {
                    if(i == 0) {
                        paste = cur = pr.first;
                    } else {
                        cur = pr.first + pr.second;
                        paste = pr.second;
                    }
                    if(cur == n) return k;
                    if(cur < n && paste < n && !memo[cur][paste]) {
                        memo[cur][paste] = true;
                        tlvl.emplace_back(cur, paste);
                    }
                }
            }
            lvl.swap(tlvl);
        }
        return -1;
    }
};
