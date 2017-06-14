class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int pow = 1;
        for(int y = x / 10; y != 0; y /= 10)
            pow *= 10;
        for(int low = 1, high = pow; high > low; low *= 10, high /= 10) {
            int lowNum = x / low % 10;
            int highNum = x / high % 10;
            if(lowNum != highNum) return false;
        }
        return true;
    }
};
