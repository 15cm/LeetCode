class Solution {
public:
    int findComplement(int num) {
        int mask = 0;
        for(int x = num, i = 1; x > 0; x >>= 1, i <<= 1)
            mask += i;
        return num ^ mask;
    }
};
