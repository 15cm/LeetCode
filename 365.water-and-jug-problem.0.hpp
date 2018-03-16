class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(x + y < z) return false;
        if(x == z || y == z || x+y == z) return true;
        return z % gcd(x, y) == 0;
    }
    int gcd(int a, int b) {
        return b ? gcd(b, a%b) : a;
    }
};
