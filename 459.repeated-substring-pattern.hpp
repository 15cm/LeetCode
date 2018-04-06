class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for(int i = 0; i < n/2; i++) {
            int l = i+1;
            if(n % l != 0) continue;
            bool ok = true;
            for(int j = 0; j < l; j++) {
                for(int k = j + l; k < n; k += l) {
                    if(s[k] != s[j]) {
                        ok = false;
                        break;
                    }
                }
                if(!ok) break;
            }
            if(ok) return true;
        }
        return false;
    }
};
