class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        unordered_set<string> vis;
        queue<string> q;
        q.push(s);
        vis.insert(s);
        bool found = false;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                string t = q.front(); q.pop();
                if(isValid(t)) {
                    found = true;
                    ans.push_back(t);
                }
                for(int i = 0; i < t.length(); i++) {
                    if(s[i] != '(' && s[i] != ')') continue;
                    string s0 = t.substr(0, i) + t.substr(i + 1);
                    if(!vis.count(s0)) {
                        vis.insert(s0);
                        q.push(s0);
                    }
                }
            }
            if(found) break;
        }
        return ans;
    }
    bool isValid(string& s) {
        int lp = 0;
        for(char c: s) {
            if(c == '(') {
                lp++;
            } else if(c == ')') {
                lp--;
            }
            if(lp < 0) return false;
        }
        return lp == 0;
    }
};
