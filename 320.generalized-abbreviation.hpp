class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        string path;
        vector<string> ans;
        dfs(0, false, word, path, ans);
        return ans;
    }
    void dfs(int p, bool abbr, string& word, string path, vector<string>& ans) {
        int n = word.length();
        if(p == n) {
            ans.push_back(path);
            return;
        }

        if(!abbr) {
            for(int i = 1; p + i <= n; i++) {
                dfs(p + i, true, word, path + to_string(i), ans);
            }
        }
        dfs(p + 1, false, word, path + string(1, word[p]), ans);
    }
};
