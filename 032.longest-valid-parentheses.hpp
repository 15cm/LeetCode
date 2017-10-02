class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.empty()) return 0;
        int n = s.length(), ans = 0;
        vector<int> f(n+1);
        for(int i = 2; i <= n; i++) {
            int j = i - 1;
            if(s[j] == ')') {
                if(s[j-1] == '(') {
                    f[i] = f[i-2] + 2;
                    ans = max(ans, f[i]);
                } else {
                    if(s[j - f[i-1] - 1] == '(') {
                        f[i] = f[i-1] + 2 + f[i - f[i-1] - 2];
                        ans = max(ans, f[i]);
                    }
                }
            }
        }
        return ans;
    }
};
