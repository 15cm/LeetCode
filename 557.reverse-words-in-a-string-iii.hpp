class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        for(int i = 0, j = -1; i <= n; i++) {
            if(i < n && s[i] != ' ') {
                if(j == -1) {
                    j = i;
                }
            } else {
                if(j != -1) {
                    reverse(s.begin() + j, s.begin() + i);
                    j = -1;
                }
            }
        }
        return s;
    }
};
