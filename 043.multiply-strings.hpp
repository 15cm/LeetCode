#include <iostream>
#include <cstring>
using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
        int digit[220];
        int n1 = num1.length(), n2 = num2.length();
        memset(digit, 0, sizeof digit);
        for(int i = 0; i < n1; i ++) {
            for(int j = 0; j < n2; j ++) {
                digit[i + j] += (num1[n1-1-i] - '0') * (num2[n2-1-j] - '0');
            }
        }
        for(int i = 0; i < 219; i ++) {
            digit[i+1] += digit[i] / 10;
            digit[i] %= 10;
        }
        int initial = 219;
        for(; initial > 0; initial--) {
            if(digit[initial] > 0) break;
        }
        string ans;
        for(; initial >= 0; initial--) {
            ans.push_back(digit[initial] + '0');
        }
        return ans;
    }
};
