class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> cnt(26);
        int n = p.size();
        for(int i = 0, len = 0; i < n; i++) {
            if(i > 0 && check(p[i-1], p[i])) {
                len++;
            } else {
                len = 1;
            }
            int idx = p[i] - 'a';
            cnt[idx] = max(cnt[idx], len);
        }
        int ans = 0;
        for(int x: cnt)
            ans += x;
        return ans;
    }
    bool check(char left, char right) {
        return left == 'z' ? right == 'a' : right - left == 1;
    }
};
