class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int lo = 1, hi = m * n;
        while(lo < hi) {
            int mi = lo + (hi - lo) / 2;
            if(engough(mi, m, n, k)) hi = mi;
            else lo = mi + 1;
        }
        return hi;
    }

    bool engough(int x, int m, int n, int k) {
        int cnt = 0;
        for(int i = 1; i<= m; i++) {
            cnt += min(x / i, n);
        }
        return cnt >= k;
    }
};
