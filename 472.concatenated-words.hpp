class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end(), [](const auto &lhs, const auto &rhs) {
                return lhs.size() < rhs.size();
            });
        vector<string> ans;
        unordered_set<string> preWords;
        int n = words.size();

        for(auto &word: words) {
            if(canForm(word, preWords)) {
                ans.push_back(word);
            }
            preWords.insert(word);
        }
        return ans;
    }
    bool canForm(const string& s, const unordered_set<string>& st) {
        if(st.empty()) return false;
        int n = s.size();
        vector<bool> dp(n+1);
        dp[0] = true;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < i; j++) {
                if(dp[j] && st.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
