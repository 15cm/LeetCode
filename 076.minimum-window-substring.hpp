#include <iostream>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int mp[128] = {0};
        for(auto& ch: t)
            mp[ch] ++;
        int counter = t.length(), begin = 0, end = 0, d = s.length() + 1, head = 0;
        while(end < s.length()) {
            if(mp[s[end++]]-- > 0) counter--;
            while(counter == 0) {
                if(end - begin < d) d = end - (head = begin);
                if(mp[s[begin++]]++ == 0) counter++;
            }
        }
        return d == s.length() + 1 ? "" : s.substr(head, d);
    }
};
