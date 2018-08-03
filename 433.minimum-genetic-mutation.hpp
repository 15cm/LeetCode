class Solution {
    const int len = 8;
    const char alphabet[4] = {'A', 'C', 'G', 'T'};
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> dic(bank.begin(), bank.end());
        vector<string> lvl, tlvl;
        if(start == end) return 0;
        dic.erase(start);
        lvl.push_back(start);
        int step = 0;
        while(!lvl.empty()) {
            tlvl.clear();
            step++;
            for(auto &u: lvl) {
                for(int i = 0; i < len; i++) {
                    char c = u[i];
                    for(char mutation: alphabet) {
                        if(c == mutation) continue;
                        u[i] = mutation;
                        if(dic.count(u)) {
                            if(u == end) return step;
                            dic.erase(u);
                            tlvl.push_back(u);
                        }
                    }
                    u[i] = c;
                }
            }
            lvl.swap(tlvl);
        }
        return -1;
    }
};
