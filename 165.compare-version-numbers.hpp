#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int prev1, prev2, cur1, cur2, n1 = version1.length(), n2 = version2.length();
        string curVer1, curVer2;
        prev1 = prev2 = cur1 = cur2 = 0;
        while(cur1 != n1 || cur2 != n2) {
            while(cur1 != n1 && version1[cur1++] != '.');
            while(cur2 != n2 && version2[cur2++] != '.');
            int v1, v2;
            if(cur1 == n1) {
                if(prev1 == cur1) v1 = 0;
                else v1 = stoi(version1.substr(prev1));
            } else {
                v1 = stoi(version1.substr(prev1, cur1 - prev1 - 1));
            }
            if(cur2 == n2) {
                if(prev2 == cur2) v2 = 0;
                else v2 = stoi(version2.substr(prev2));
            } else {
                v2 = stoi(version2.substr(prev2, cur2 - prev2 - 1));
            }
            if(v1 != v2s)
                return v1 > v2 ? 1 : -1;
            prev1 = cur1;
            prev2 = cur2;
        }
        return 0;
    }
};
