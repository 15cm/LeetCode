class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        int f1 = 1, f2 = 2;
        for(int i = 3; i <= n; i++) {
            int t = f2;
            f2 = f1 + f2;
            f1 = t;
        }
        return f2;
    }
};
