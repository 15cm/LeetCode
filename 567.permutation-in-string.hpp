class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> cntTpl(26), cnt(26);
        for(auto c: s1)  cntTpl[c - 'a']++;
        int k = s1.size(), n = s2.size();
        for(int i = 0; i < n; i++) {
            cnt[s2[i] - 'a']++;
            if(i >= k - 1) {
                if(i >= k) {
                    cnt[s2[i - k] - 'a']--;
                }
                if(cntTpl == cnt) return true;
            }
        }
        return false;
    }
};
