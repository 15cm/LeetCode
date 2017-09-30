typedef vector<int> V;
typedef vector<V> VV;
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        VV dfa = buildDFA(needle, 128);
        int n = haystack.size(), m = needle.size();
        int i, j;
        for(i = 0, j = 0; i < n && j < m; i++) {
            j = dfa[haystack[i]][j];
        }
        return j == m ? i - m : -1;
    }
    VV buildDFA(string& pattern, int R) {
        int n = pattern.size();
        VV dfa(R, V(n));
        dfa[pattern[0]][0] = 1;
        for(int i = 1, x = 0; i < n; i++) {
            for(int c = 0; c < R; c++)
                dfa[c][i] = dfa[c][x];
            dfa[pattern[i]][i] = i + 1;
            x = dfa[pattern[i]][x];
        }
        return dfa;
    }
};
