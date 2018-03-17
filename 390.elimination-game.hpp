class Solution {
public:
    int lastRemaining(int n) {
        bool left = true;
        int head = 1, step = 1;
        int rem = n;
        while(rem > 1) {
            if(left || rem & 1) {
                head += step;
            }
            step <<= 1;
            rem >>= 1;
            left = !left;
        }
        return head;
    }
};
