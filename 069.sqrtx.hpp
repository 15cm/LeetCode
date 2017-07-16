#include <iostream>
#include <cmath>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        if(x < 0) return (1 << 31);
        int l = 0, r = x / 2 + 1, m = (r - l) / 2  + l;
        while(l < r - 1) {
            long diff = (long)(m) * (long)(m) - x;
            if(diff > 0) r = m;
            else if(diff < 0) l = m;
            else return m;
            m = (r - l) / 2 + l;
        }
        return r * r == x ? r : l;
    }
};
