class Solution {
public:
    int countSegments(string s) {
        if(s.empty()) return 0;
        int cnt = 0;
        int n = s.length();
        for(int i = 0; i < n; i++) {
            if(s[i] == ' ' && i > 0 && s[i-1] != ' ')
                cnt++;
        }
        if(s.back() != ' ') cnt++;
        return cnt;
    }
};
