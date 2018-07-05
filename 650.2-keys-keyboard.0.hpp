class Solution {
public:
    int minSteps(int n) {
        int ans = 0, k = 2;
        while(n > 1) {
            while(n % k == 0) {
                ans += k;
                n /= k;
            }
            k++;
        }
        return ans;
    }
};
