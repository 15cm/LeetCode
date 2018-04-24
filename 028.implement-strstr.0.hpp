class Solution {
public:
    int strStr(string haystack, string needle) {
        auto &t = haystack, &p = needle;
        int n = t.size(), m = p.size();
        if(m == 0) return 0;
        vector<int> fail(m);
        for(int i = 0, j = -1; i < m; i++, j++) {
            if(j >= 0 && p[i] == p[j]) {
                fail[i] = fail[j];
            } else {
                fail[i] = j;
            }
            while(j >= 0 && p[i] != p[j])
                j = fail[j];
        }

        for(int i = 0, j = 0; i < n; i++, j++) {
            while(j >= 0 && t[i] != p[j]) {
                j = fail[j];
            }
            if(j == m - 1) return i - m + 1;
        }
        return -1;
    }
};
