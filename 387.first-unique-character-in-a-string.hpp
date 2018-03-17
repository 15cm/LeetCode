class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.length();
        pair<int, int> cnt[26] = {{0, 0}};
        for(int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            cnt[idx].first++;
            cnt[idx].second = i;
        }
        int minIdx = n;
        for(int i = 0; i < 26; i++) {
            auto& pr = cnt[i];
            if(pr.first == 1)
                minIdx = min(pr.second, minIdx);
        }
        return minIdx == n ? -1 : minIdx;
    }
};
