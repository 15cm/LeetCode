class Solution {
public:
    int longestSubstring(string s, int k) {
        vector<int> mp(26,0);
        int d = 0;
        for(int h = 1; h <= 26; h++) {
            fill(mp.begin(), mp.end(), 0);
            int i = 0, j = 0, unique = 0, noLessThan = 0;
            while(j < s.size()) {
                int cnt = mp[s[j] - 'a'];
                if(cnt == 0) unique++;
                if(cnt == k-1) noLessThan++;
                mp[s[j++] - 'a']++;
                while(unique > h || noLessThan > h) {
                    int cnt = mp[s[i] - 'a'];
                    if(cnt == 1) unique--;
                    if(cnt == k) noLessThan--;
                    mp[s[i++] - 'a']--;
                }
                if(unique == h && noLessThan == h) {
                    d = max(j - i, d);
                }
            }
        }
        return d;
    }
};
