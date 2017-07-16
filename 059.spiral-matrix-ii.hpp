#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> m(n, vector<int>(n, 0));
        int num = 1;
        int r1 = 0, c1 = 0, r2 = n - 1, c2 = n - 1;
        for(; r1 < r2 && c1 < c2; r1++, c1++, r2--, c2--)
            fillMargin(r1, c1, r2, c2, num, m);
        if(r1 == r2) for(int c = c1; c <= c2; c++) m[r1][c] = num++;
        else if(c1 == c2) for(int r = r1; r <= r2; r++) m[r][c1] = num++;
        return m;
    }
    void fillMargin(int r1, int c1, int r2, int c2, int& num, vector<vector<int>>& m) {
        for(int c = c1; c <= c2; c ++) m[r1][c] = num++;
        for(int r = r1 + 1; r <= r2; r ++) m[r][c2] = num++;
        for(int c = c2 - 1; c >= c1; c --) m[r2][c] = num++;
        for(int r = r2 - 1; r >= r1 + 1; r --) m[r][c1] = num++;
    }
};
