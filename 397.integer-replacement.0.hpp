class Solution {
public:
    int integerReplacement(int n) {
        int c = 0;
        unsigned int x = n;
        while(x != 1) {
            if(!(x & 1)) {
                x >>= 1;
            } else if(x == 3 || ((x >> 1) & 1) == 0) {
                x--;
            } else {
                x++;
            }
            c++;
        }
        return c;
    }
};
