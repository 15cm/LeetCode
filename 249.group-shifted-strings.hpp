class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> mp;
        for(auto& s: strings) {
            int d = s[0] - 'a';
            string t = s;
            for(char& c: t) {
                c = ((c - 'a') - d + 26) % 26 + 'a';
            }
            mp[t].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto& pr: mp) {
            ans.push_back(pr.second);
        }
        return ans;
    }
};
