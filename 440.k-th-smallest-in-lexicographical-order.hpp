class Solution {
public:
    int findKthNumber(int n, int k) {
        int cur = 1;
        k--;
        while(k) {
            int steps = calSteps(n, cur, cur+1);
            if(steps <= k) {
                k -= steps;
                cur++;
            } else {
                cur *= 10;
                k -= 1;
            }
        }
        return cur;
    }
    int calSteps(int n, long p, long q) {
        int steps = 0;
        while(p <= n) {
            steps += min((long)n+1, q) - p;
            p *= 10;
            q *= 10;
        }
        return steps;
    }
};
