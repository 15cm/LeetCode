class Solution {
public:
    void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        int n = s.length(), pos = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] != ' ') {
                if(pos != 0) s[pos++] = ' ';
                int j = i;
                while(j < n && s[j] != ' ') s[pos++] = s[j++];
                reverse(s.begin() + pos - (j - i), s.begin() + pos);
                i = j;
            }
        }
        s.erase(s.begin() + pos, s.end());
    }
};
