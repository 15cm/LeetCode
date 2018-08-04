class Solution {
public:
    string minWindow(string S, string T) {
        int n = S.size(), m = T.size();
        vector<int> cur(n, -1), next(n, -1);
        for(int i = 0; i < n; i++)
            if(S[i] == T[0]) cur[i] = i;
        for(int j = 1; j < m; j++) {
            fill(next.begin(), next.end(), -1);
            int last = -1;
            for(int i = 0; i < n; i++) {
                if(last != -1 && S[i] == T[j]) next[i] = last;
                if(cur[i] != -1) last = cur[i];
            }
            cur.swap(next);
        }
        int start = 0, len = n + 1;
        for(int i = 0; i < n; i++) {
            if(cur[i] == -1) continue;
            int l = i - cur[i] + 1;
            if(l < len) {
                start = cur[i];
                len = l;
            }
        }
        return len == n + 1 ? "" : S.substr(start, len);
    }
};
