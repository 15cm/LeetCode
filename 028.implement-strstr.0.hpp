class Solution {
public:
    int strStr(string haystack, string needle) {
        string& txt = haystack, &pat = needle;
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
    vector<int> getFail(string& pat) {
        int m = pat.length();
        vector<int> fail(m);
        for(int i = 0, j = -1; i < m; i++, j++) {
            if(j >= 0 && pat[i] == pat[j])
                fail[i] = fail[j];
            else
                fail[i] = j;
            while(j >= 0 && pat[i] != pat[j])
                j = fail[j];
        }
        return fail;
    }
};
