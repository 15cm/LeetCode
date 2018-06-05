class Solution {
public:
    int findIntegers(int num) {
        vector<int> f(32);
        f[0] = 1;
        f[1] = 2;
        for(int i = 2; i < 32; i++)
            f[i] = f[i-1] + f[i-2];
        bool prevBitIsOne = false;
        int sum = 0;
        for(int i = 30; i >= 0; i--) {
            if(num & (1 << i)) {
                sum += f[i];
                if(prevBitIsOne) {
                    sum--;
                    break;
                }
                prevBitIsOne = true;
            } else {
                prevBitIsOne = false;
            }
        }
        return sum + 1;
    }
};
