#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> grayCode(int n) {
        if(n == 0) return {0};
        vector<int> lastSeq, seq;
        lastSeq = seq = grayCode(n - 1);
        seq.resize(1 << n);
        for(int i = lastSeq.size() - 1; i >= 0; i--) {
            seq[(1 << n) - 1 - i] = lastSeq[i] + (1 << (n - 1));
        }
        return seq;
    }
};
