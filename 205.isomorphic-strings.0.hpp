class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> mp(128, -1), rev_mp(128, -1);
        for(int i = 0; i < s.size(); i++) {
            int &val = mp[s[i]], &rev_val = rev_mp[t[i]];
            if(val == -1) {
                if(rev_val != -1 && rev_val != s[i])
                    return false;
                val = t[i];
                if(rev_val == -1)
                    rev_val = s[i];
            } else {
                if(val != t[i]) return false;
            }
        }
        return true;
    }
};
