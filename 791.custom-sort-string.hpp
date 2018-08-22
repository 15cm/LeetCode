class Solution {
public:
    string customSortString(string S, string T) {
        vector<int> cnt(26);
        for(char c: T) cnt[c - 'a']++;
        string ans;
        for(char c: S) {
            int idx = c - 'a';
            ans.append(cnt[idx], c);
            cnt[idx] = 0;
        }
        for(int i = 0; i < 26; i++) {
            if(cnt[i] != 0)
                ans.append(cnt[i], i + 'a');
        }
        return ans;
    }
};
