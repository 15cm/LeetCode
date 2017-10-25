class Solution {
public:
    int lengthLongestPath(string input) {
        int ans = 0;
        stringstream ss(input);
        string s;
        stack<int> dir;
        while(getline(ss, s, '\n')) {
            int start = 0;
            while(s[start] == '\t') start++;
            while(dir.size() > start)
                dir.pop();
            dir.push((dir.empty() ? 0 : dir.top() + 1) + s.length() - start);
            int dotPos = s.find(".");
            if(dotPos != string::npos && dotPos != s.length() - 1) {
                ans = max(ans, dir.top());
            }
        }
        return ans;
    }
};
