class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int R = 26;
        string mp[R] = {""};
        stringstream ss(str);
        int p = 0;
        string s;
        while(getline(ss, s, ' ')) {
            if(p >= pattern.length()) return false;
            int index = charToIndex(pattern[p]);
            if(mp[index].empty())
                mp[index] = s;
            else if(mp[index] != s) return false;
            p++;
        }
        if(p != pattern.length()) return false;
        unordered_set<string> rec;
        for(int i = 0; i < R; i++) {
            if(!mp[i].empty()) {
                if(rec.count(mp[i])) return false;
                else rec.insert(mp[i]);
            }
        }
        return true;
    }
    int charToIndex(char c) {
        return c - 'a';
    }
};
