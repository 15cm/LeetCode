class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.length();
        for(int i = 1; i <= n/2; i++) {
            if(num[0] == '0' && i > 1) break;
            long a = stol(num.substr(0, i));
            for(int j = i+1; max(i, j-i) <= n - j; j++) {
                if(num[i] == '0' && j > i+1) break;
                long b = stol(num.substr(i, j-i));
                if(dfs(a, b, j, num)) return true;
            }
        }
        return false;
    }
    bool dfs(long a, long b, int p, string& s) {
        int n = s.length();
        if(p == n) return true;
        long sum = a + b;
        string t = to_string(sum);
        int m = t.length();
        for(int i = 0; i < m; i++) {
            int j = p + i;
            if(j == n || t[i] != s[j]) return false;
        }
        return dfs(b, sum, p+m, s);
    }
};
