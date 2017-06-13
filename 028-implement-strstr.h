#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        for(int i = 0; i < haystack.length(); i ++) {
            int j = 0;
            for(; j < needle.length(); j++) {
                if(i + j >= haystack.length()) return -1;
                if(haystack[i + j] != needle[j]) break;
            }
            if(j == needle.length()) return i;
        }
        return -1;
    }
};
