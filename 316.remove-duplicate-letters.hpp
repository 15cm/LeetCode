class Solution {
public:
    string removeDuplicateLetters(string s) {
        if(s.empty()) return "";
        int cnt[26] = {0};
        int pos = 0;
        for(char c: s) cnt[c - 'a']++;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] < s[pos]) pos = i;
            if(--cnt[s[i] - 'a'] == 0) break;
        }
        string t;
        for(int i = pos + 1; i < s.length(); i++) {
            if(s[i] != s[pos])
                t.push_back(s[i]);
        }
        return s.substr(pos, 1) + removeDuplicateLetters(t);
    }
};
