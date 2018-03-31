class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0, maxCnt = 0;
        vector<int> cnt(26);
        int n = s.length();
        int i = 0;
        for(int j = 0; j < n;) {
            maxCnt = max(maxCnt, ++cnt[s[j++] - 'A']);
            if(maxCnt + k < j - i)
                cnt[s[i++] - 'A']--;
        }
        return n - i;
    }
};
