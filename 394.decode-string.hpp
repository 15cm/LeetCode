class Solution {
public:
    string decodeString(string s) {
        stack<int> numStk;
        stack<string> strStk;
        string ans;

        int n = s.length();
        for(int i = 0; i < n; i++) {
            char c = s[i];
            if(c >= '0' && c <= '9') {
                int j = i;
                while(s[j] != '[') j++;
                numStk.push(stoi(s.substr(i, j - i)));
                strStk.push("");
                i = j;
            } else if(c == ']') {
                string t = strStk.top(); strStk.pop();
                int num = numStk.top(); numStk.pop();
                string tmp;
                while(num--) tmp += t;
                if(!numStk.empty()) {
                    strStk.top() += tmp;
                } else {
                    ans += tmp;
                }
            } else if(!numStk.empty()){
                strStk.top().push_back(c);
            } else {
                ans.push_back(c);
            }
        }
        return ans;
    }
};
