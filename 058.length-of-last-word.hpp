#include <iostream>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length(), i = 0;
        while(i < n && s[i] == ' ') i++;
        if(i == n) return 0;
        int j = i;
        while(i < n) {
            while(i < n && s[i] != ' ') i++;
            if(i == n) return i - j;
            int t = i;
            while(i < n && s[i] == ' ') i++;
            if(i == n) return t - j;
            j = i;
        }
        return i - j;
    }
};
