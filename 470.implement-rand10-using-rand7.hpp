// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int col, row, res;
        do {
            row = rand7() - 1;
            col = rand7() - 1;
            res = row * 7 + col;
        } while(res > 39);
        return res % 10 + 1;
    }
};
