class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        if(n1 == 0) return 0;
        vector<int> idxs(s2.size() + 1), cnts(s2.size() + 1);
        int idx = 0, cnt = 0;
        for(int i = 0; i < n1; i++) {
            // ever s1 block
            for(int j = 0; j < s1.size(); j++) {
                if(s1[j] == s2[idx]) {
                    idx++;
                }
                if(idx == s2.size()) {
                    idx = 0;
                    cnt++;
                }
            }
            idxs[i] = idx;
            cnts[i] = cnt;
            for(int k = 0; k < i; k++) {
                if(idxs[k] == idxs[i]) {
                    int prevCnt = cnts[k];
                    int patternCnt = (cnts[i] - cnts[k]) * ((n1-1 - k) / (i - k));
                    int remainCnt = (cnts[k + (n1-1-k) % (i-k)] - cnts[k]);
                    return (prevCnt + patternCnt + remainCnt) / n2;
                }
            }
        }
        return cnts[n1-1]/n2;
    }
};
