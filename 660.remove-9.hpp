class Solution {
public:
    int newInteger(int n) {
        return base10to9(n);
    }
    int base10to9(int n) {
        int ans = 0, exp = 1;
        while(n) {
            ans += n % 9 * exp;
            n /= 9;
            exp *= 10;
        }
        return ans;
    }
};
