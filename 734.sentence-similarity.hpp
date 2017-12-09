class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        int n = words1.size(), m = words2.size();
        if(n != m) return false;
        unordered_map<string, unordered_set<string>> mp;
        for(auto& pr: pairs) {
            mp[pr.first].insert(pr.second);
        }
        for(int i = 0; i < n; i++) {
            string &s = words1[i], &t = words2[i];
            if(!(s == t || mp[s].count(t) || mp[t].count(s)))
                return false;
        }
        return true;
    }
};
