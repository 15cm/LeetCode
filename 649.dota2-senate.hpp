class Solution {
public:
    string predictPartyVictory(string senate) {
        set<int> rs, ds;
        for(int i = 0; i < senate.size(); i++) {
            if(senate[i] == 'R') rs.insert(i);
            else ds.insert(i);
        }
        int cur = -1;
        while(!(rs.empty() || ds.empty())) {
            auto rit = rs.upper_bound(cur);
            auto dit = ds.upper_bound(cur);
            if(rit == rs.end() && dit == ds.end()) {
                cur = -1;
            } else if(dit == ds.end() || rit != rs.end() && *rit < *dit){
                cur = *rit;
                if(dit == ds.end()) {
                    dit = ds.begin();
                }
                ds.erase(dit);
            } else {
                cur = *dit;
                if(rit == rs.end()) {
                    rit = rs.begin();
                }
                rs.erase(rit);
            }
        }
        return rs.empty() ? "Dire" : "Radiant";
    }
};
