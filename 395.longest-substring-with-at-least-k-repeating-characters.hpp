class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length(), ans = 0;
        if(k == 0) return n;
        for(int h = 1; h <= 26; h++) {
            int i = 0, j = 0, unik = 0, moreThanK = 0;
            int cnt[26] = {0};
            while(j < n) {
                int idx = ctoi(s[j]);
                if(cnt[idx] == 0) {
                    unik++;
                }
                if(cnt[idx] == k - 1) {
                    moreThanK++;
                }
                cnt[idx]++;
                j++;
                while(unik > h) {
                    int v = cnt[ctoi(s[i++])]--;
                    if(v == 1) unik--;
                    if(v == k) moreThanK--;
                }
                if(unik == h && moreThanK == unik) {
                    ans = max(ans, j - i);
                }
            }
        }
        return ans;
    }
    int ctoi(char c) {
        return c - 'a';
    }
};
