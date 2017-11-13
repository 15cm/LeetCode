class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        string s;
        int cnt = 0;
        while(s.length() < B.length()) {
            s += A;
            cnt++;
        }
        if(search(s, B) >= 0) return cnt;
        s += A; cnt++;
        if(search(s, B) >= 0) return cnt;
        return -1;
    }
    int search(string& txt, string& pat) {
        int n = txt.length(), m = pat.length();
        if(m == 0) return 0;
        auto fail = getFail(pat);
        for(int i = 0, j = 0; i < n; i++, j++) {
            while(j >= 0 && txt[i] != pat[j])
                j = fail[j];
            if(j == m - 1)
                return i - m + 1;
        }
        return -1;
    }
    vector<int> getFail(string& p) {
        int m = p.length();
        vector<int> fail(m);
        for(int i = 0, j = -1; i < m; i++, j++) {
            if(j >= 0 && p[i] == p[j])
                fail[i] = fail[j];
            else
                fail[i] = j;
            while(j >= 0 && p[i] != p[j])
                j = fail[j];
        }
        return fail;
    }
};
