#include <iostream>

using namespace std;

class Solution {
public:
    int min(int a, int b) {return a < b ? a : b;}
    string longestPalindrome(string s) {
        if(s.length() == 0) return "";
        if(s.length() == 1) return s;
        string _s = "^#";
        for(auto& c: s) {
            _s.append(1, c);
            _s.append(1, '#');
        }
        _s.append(1, '$');
        int m = _s.length(), maxLen = 0, maxIndex, pos, maxRight = 2;
        int r[m];
        for(int i = 0; i < m; i ++) r[i] = 0;
        for(int i = 2; i < m - 3; i ++) {
            if(i < maxRight) {
                r[i] = min(r[2 * pos - i], maxRight - i);
            } else {
                r[i] = 1;
            }
            while(r[i] < min(i, m - 1 - i) && _s[i - r[i]] == _s[i + r[i]])
                r[i] ++;
            if(r[i] + i - 1 > maxRight) {
                maxRight = r[i] + i - 1;
                pos = i;
            }
            if(r[i] > maxLen) {
                maxLen = r[i];
                maxIndex = i;
            }
        }
        return s.substr((maxIndex - maxLen) / 2, maxLen - 1);
    }
};
