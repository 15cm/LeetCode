class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(), strs.end(), [](const auto & lhs, const auto &rhs) {
                return lhs.size() > rhs.size();
            });
        int n = strs.size();
        for(int i = 0; i < n; i++) {
            bool ok = true;
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                if(isSubseq(strs[j], strs[i])) {
                    ok = false;
                    break;
                }
            }
            if(ok)
                return strs[i].size();
        }
        return -1;
    }
    bool isSubseq(const string &s, const string& t) {
        int j = 0, n = s.size(), m = t.size();
        for(int i = 0; i < n && j < m; i++) {
            if(s[i] == t[j])
                j++;
        }
        return j == m;
    }
};
