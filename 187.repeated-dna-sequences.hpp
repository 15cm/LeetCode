class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> mp;
        vector<string> ans;
        for(int i = 0; i + 9 < s.length(); i++) {
            string t = s.substr(i, 10);
            switch(mp[t]) {
                case 0:
                    mp[t] = 1;
                    break;
                case 1:
                    ans.push_back(t);
                    mp[t] = -1;
                    break;
            }
        }
        return ans;
    }
};
