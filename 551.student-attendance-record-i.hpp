class Solution {
public:
    bool checkRecord(string s) {
        int cntA, cntL;
        cntA = cntL = 0;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(s[i] == 'A') {
                if(++cntA > 1) return false;
            } else if(i > 1 && s[i] == 'L' && s[i-1] == 'L' && s[i-2] == 'L') {
                return false;
            }
        }
        return true;
    }
};
