class Solution {
public:
    int reverse(int x) {
        const int posMax = 0x7FFFFFFF;
        const int negMax = 0x80000000; 
        int ans = 0;
        while(x != 0) {
            if(x > 0) {
                if((posMax - x % 10) / 10 < ans) return 0;
            } else {
                if((negMax - x % 10) / 10 > ans) return 0;
            }
            ans *= 10;
            ans += x % 10;
            x /= 10;
        }
        return ans;
    }
};
