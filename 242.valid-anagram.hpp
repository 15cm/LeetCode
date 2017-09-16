class Solution {
public:
    bool isAnagram(string s, string t) {
        const int R = 256;
        int cnt[R] = {0};
        if(s.length() != t.length()) return false;
        for(int i = 0; i < s.length(); i++) {
            cnt[s[i]]++;
            cnt[t[i]]--;
        }
        for(int i = 0; i < R; i++)
            if(cnt[i]) return false;
        return true;
    }
};
