class Solution {
    map<char, char> mp = {
        {'0', '0'},
        {'1', '1'},
        {'6', '9'},
        {'9', '6'},
        {'8', '8'},
    };
    const char symmetry[3] = {'0', '1', '8'};
public:
    vector<string> findStrobogrammatic(int n) {
        vector<string> ans;
        string s(n, ' ');
        dfs(0, n - 1, s, ans);
        return ans;
    }
    void dfs(int p, int q, string& s, vector<string>& ans) {
        if(p == q) {
            for(char c: symmetry) {
                s[p] = c;
                ans.push_back(s);
            }
            return;
        }
        if(p > q) {
            ans.push_back(s);
            return;
        }

        for(auto& kv: mp) {
            if(kv.first == '0' && p == 0) continue;
            s[p] = kv.first;
            s[q] = kv.second;
            dfs(p + 1, q - 1, s, ans);
        }
    }
};
