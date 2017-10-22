class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        auto lps = computeLpsArray(needle);
        int n = haystack.length(), m = needle.length();
        for(int i = 0, j = 0; i < n;) {
            if(haystack[i] == needle[j]) {
                i++;
                j++;
            }

            if(j == m) {
                return i - j;
            }
            if(i < n && haystack[i] != needle[j]) {
                if(j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }
        return -1;
    }
    vector<int> computeLpsArray(string& pat) {
        int n = pat.length(), len = 0, i = 1;
        vector<int> lps(n);

        while(i < n) {
            if(pat[i] == pat[len]) {
                lps[i++] = ++len;
            } else {
                if(len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i++] = 0;
                }
            }
        }

        return lps;
    }
};
