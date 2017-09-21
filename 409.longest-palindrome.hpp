class Solution {
public:
    int longestPalindrome(string s) {
        int cnt[52] = {0};
        int ans = 0;
        for(auto c: s) {
            int index = charToIndex(c);
            if(cnt[index] > 0) {
                cnt[index]--;
                ans += 2;
            } else {
                cnt[index]++;
            }
        }
        for(int i = 0; i < 52; i++)
            if(cnt[i]) {
                ans++;
                break;
            }
        return ans;
    }
    int charToIndex(char c) {
        if(c >= 'a' && c <= 'z')
            return c - 'a';
        else
            return c - 'A' + 26;
    }
};
