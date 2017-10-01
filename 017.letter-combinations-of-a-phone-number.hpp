class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<vector<char>> mp = {
            {'a','b','c'},
            {'d','e','f'},
            {'g','h','i'},
            {'j','k','l'},
            {'m','n','o'},
            {'p','q','r','s'},
            {'t','u','v'},
            {'w','x','y','z'}
        };
        vector<string> ans;
        if(digits.empty()) return ans;
        string path;
        dfs(0, digits, path, ans, mp);
        return ans;
    }
    void dfs(int cur, string& digits, string& path, vector<string>& ans, vector<vector<char>>& mp) {
        if(cur == digits.size()) ans.push_back(path);
        for(char c: mp[digits[cur] - '2']) {
            path += c;
            dfs(cur + 1, digits, path, ans, mp);
            path.pop_back();
        }
    }
};
