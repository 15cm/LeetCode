class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_set<string> dic(wordDict.begin(), wordDict.end());
        vector<list<string>> f(n + 1);

        vector<bool> f0(n + 1, false);
        f0[0] = true;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < i; j++) {
                if(f0[j] && dic.count(s.substr(j, i - j))) {
                    f0[i] = true;
                    break;
                }
            }
        }
        if(!f0[n]) return vector<string>();

        f[0].push_back("");
        for(int i = 1; i <= n; i++) {
            for(int j = i - 1; j >= 0; j--) {
                string subs = s.substr(j, i - j);
                if(dic.find(subs) != dic.end()) {
                    for(auto& st: f[j]) {
                        string tmps = st.empty() ? st + subs : st + " " + subs;
                        f[i].push_back(tmps);
                    }
                }
            }
        }
        return vector<string>(f[n].begin(), f[n].end());
    }
};
