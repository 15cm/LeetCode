class Solution {
public:
    int reverse(int x) {
        long long val = 0;
        do{
            val = val * 10 + x % 10;
            x /= 10;
        }while(x);
        return (val < INT_MIN || val > INT_MAX) ? 0 : val;
    }
};
