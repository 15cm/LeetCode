class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        vector<int> counts(26);
        int cnt = m;
        for(char c: s1) counts[c - 'a']++;
        for(int i = 0; i < n; i++) {
            if(counts[s2[i] - 'a']-- > 0) cnt--;
            if(i >= m && counts[s2[i - m] - 'a']++ >= 0) cnt++;
            if(cnt == 0) return true;
        }
        return false;
    }
};
