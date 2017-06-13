#include <iostream>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const int charSetSize = 128;
        int d[charSetSize], n = s.length(), ans = 0;
        for(int i = 0; i < charSetSize; i ++) d[i] = 0;
        for(int i = 0, j = 0; j < n; j ++) {
            if(d[s[j]] > i) i = d[s[j]];
            if(j - i + 1 > ans) ans = j - i + 1;
            d[s[j]] = j + 1;
        }
        return ans;
    }
};
