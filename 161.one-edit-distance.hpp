class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int n = s.length(), m = t.length(), diff = abs(n-m);
        if(diff >= 2) return false;
        for(int i = 0, j = 0; i < n && j < m; i++, j++) {
            if(s[i] != t[j]) {
                string s1 = s.substr(i), s2 = s.substr(i+1), t1 = t.substr(j), t2 = t.substr(j+1);
                if(s2 == t2 || s1 == t2 || s2 == t1) return true;
                else return false;
            }
        }
        return diff == 1;
    }
};
