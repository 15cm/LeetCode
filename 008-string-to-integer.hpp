#include <iostream>

using namespace std;

class Solution {
public:
    int char2num(char c) {
        return c - '0';
    }
    int myAtoi(string str) {
        const int int_max = 0x7FFFFFFF;
        const int int_min = 0x80000000;
        if(str.length() == 0) return 0;
        long ans = 0;
        int sign = 1, i = 0;
        while(str[i] == ' ' || str[i] == '\t' || str[i] == '\n') i++;
        if(str[i] == '+') i++;
        else if(str[i] == '-') {
            sign = -1;
            i++;
        }
        else if(str[i] == '0') while(str[i] == '0') i++;
        for(; i < str.length() && str[i] >= '0' && str[i] <= '9'; i++) {
            ans *= 10;
            ans += char2num(str[i]);
            if(sign == 1 && ans > int_max) return int_max;
            if(sign == -1 && ans - 1 > int_max) return int_min;
        }
        if(sign == -1) ans = -ans;
        return ans;
    }
};
