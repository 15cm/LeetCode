class Solution {
public:
    string simplifyPath(string path) {
        string ans, tmp;
        stringstream ss(path);
        list<string> stk;
        while(getline(ss, tmp, '/')) {
            if(tmp.empty() || tmp == ".") continue;
            if(tmp == "..") {
                if(!stk.empty()) {
                    stk.pop_back();
                }
            } else {
                stk.push_back(tmp);
            }
        }
        for(string& s: stk) {
            ans += "/" + s;
        }
        return ans.empty() ? "/" : ans;
    }
};
