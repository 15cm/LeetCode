class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if(n == 0) return 0;
        int prev = 1, cur = s[n-1] == '0' ? 0 : 1, next = 0;
        if(n == 1) return cur;
        for(int i = n - 2; i >= 0; i--) {
            if(s[i] == '0') next = 0;
            else {
                next = stoi(s.substr(i,2)) <= 26 ? prev + cur : cur;
            }
            prev = cur;
            cur = next;
        }
        return next;
    }
};
