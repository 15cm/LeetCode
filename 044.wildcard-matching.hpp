typedef vector<int> VI;
typedef vector<VI> VVI;
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        VVI memo(m+1, VI(n+1, -1));
        return helper(0, 0, s, p, memo);
    }
    bool helper(int i, int j, string& s, string& p, VVI& memo) {
        if(memo[i][j] != -1) {
            return memo[i][j];
        }
        int m = s.length(), n = p.length();
        bool res;
        if(j == n) res = i == m;
        else if(i == m) {
            res = true;
            for(int k = j; k < n; k++) {
                if(p[k] != '*') {
                    res = false;
                    break;
                }
            }
        }
        else {
            if(p[j] == '?') {
                res = helper(i + 1, j + 1, s, p, memo);
            } else if(p[j] == '*') {
                res = helper(i, j + 1, s, p, memo) || helper(i + 1, j + 1, s, p, memo) || helper(i + 1, j, s, p, memo);
            } else {
                res = s[i] == p[j] && helper(i + 1, j + 1, s, p, memo);
            }
        }
        return memo[i][j] = res;
    }
};
