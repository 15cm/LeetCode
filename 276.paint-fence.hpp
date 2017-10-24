class Solution {
public:
    int numWays(int n, int k) {
        if(n == 0) return 0;
        if(n == 1) return k;
        int sameCnt = k;
        int diffCnt = k * (k-1);
        for(int i = 2; i < n; i++) {
            int tmp = diffCnt;
            diffCnt = (sameCnt + diffCnt) * (k-1);
            sameCnt = tmp;
        }
        return sameCnt + diffCnt;
    }
};
