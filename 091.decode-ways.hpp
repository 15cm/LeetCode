#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int numDecodings(string s) {
        if(s.empty()) return 0;
        int f1 = 1, f2 = s.back() == '0' ? 0 : 1;
        int n = s.length();
        for(int i = n - 2; i >= 0; i--) {
            int f0 = f1;
            f1 = f2;
            if(s[i] == '0') {
                f2 = 0;
            } else {
                int num = stoi(s.substr(i, 2));
                f2 = num <= 26 ? f0 + f1 : f1;
            }
        }
        return f2;
    }
};
