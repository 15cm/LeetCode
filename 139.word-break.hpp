class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dic(wordDict.begin(), wordDict.end());
        int n = s.length();
        vector<bool> f(n + 1, false);
        f[0] = true;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < i; j++) {
                if(f[j] && dic.find(s.substr(j, i - j)) != dic.end()) {
                    f[i] = true;
                    break;
                }
            }
        }
        return f[n];
    }
};
