class Solution {
public:
    string parseTernary(string expression) {
        int cur = 0;
        int ans = parse(cur, expression);
        if(ans < 0) {
            return ans == -1 ? "T" : "F";
        } else {
            return to_string(ans);
        }
    }
    int parse(int& p, const string& s) {
        int n = s.size();
        char c = s[p];
        if(isdigit(c)) {
            int res = 0;
            while(p < n && isdigit(s[p])) {
                res = res * 10 + s[p] - '0';
                p++;
            }
            p++;
            return res;
        }
        if(p == n - 1) {
            return s[p] == 'T' ? -1 : -2;
        }
        if(s[p+1] == ':') {
            p += 2;
            return c == 'T' ? -1 : -2;
        }
        // T/F ?
        p += 2;
        int left = parse(p, s);
        int right = parse(p, s);
        return c == 'T' ? left : right;
    }
};
