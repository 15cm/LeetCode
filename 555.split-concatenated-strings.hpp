class Solution {
public:
    string splitLoopedString(vector<string>& strs) {
        int n = strs.size();
        if(n == 0) return "";
        for(int i = 0; i < n; i++) {
            auto &s = strs[i];
            auto t = s;
            reverse(t.begin(), t.end());
            if(t > s) {
                s = t;
            }
        }
        string ans;
        for(int i = 0; i < n; i++) {
            string s = strs[i];
            int m = s.size();
            for(int j = 0; j < 2; j++) {
                if(j == 1) {
                    reverse(s.begin(), s.end());
                }
                for(int k = 0; k < m; k++) {
                    string acc = s.substr(k);
                    for(int l = i + 1; l < n; l++) {
                        acc += strs[l];
                    }
                    for(int l = 0; l < i; l++) {
                        acc += strs[l];
                    }
                    acc += s.substr(0, k);
                    if(acc > ans) {
                        ans = acc;
                    }
                }
            }
        }
        return ans;
    }
};
