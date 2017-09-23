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
            string u = q.front(); q.pop();
            if(isValid(u)) {
                ans.push_back(u);
                found = true;
            }
            if(found) continue;
            for(int i = 0; i < u.length(); i++) {
                if(u[i] == '(' || u[i] == ')') {
                    string v = u.substr(0, i) + u.substr(i + 1);
                    if(!vis.count(v)) {
                        vis.insert(v);
                        q.push(v);
                    }
                }
            }
        }
        return ans;
    }
    bool isValid(string& s) {
        int cnt = 0;
        for(char c: s) {
            if(c == '(') cnt++;
            else if(c == ')') cnt--;
            if(cnt < 0) return false;
        }
        return cnt == 0;
    }
};
