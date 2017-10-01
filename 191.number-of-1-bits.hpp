class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        do {
            if(n & 1) cnt++;
            n >>= 1;
        } while(n);
        return cnt;
    }
};
