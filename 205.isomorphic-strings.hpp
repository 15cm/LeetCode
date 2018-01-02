class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int mp_s[128] = {0}, mp_t[128] = {0};
        for(int i = 0; i < s.length(); i++) {
            char c1 = s[i], c2 = t[i];
            if(mp_s[c1] != mp_t[c2]) return false;
            mp_s[c1] = mp_t[c2] = i+1;
        }
        return true;
    }
};
