#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        if(strs.size() == 0) return "";
        if(strs.size() == 1) return strs[0];
        for(int i = 0;; i ++) {
            if(i > strs[0].length()) return ans;
            for(int j = 1; j < strs.size(); j ++) {
                if(i > strs[j].length() || strs[j][i] != strs[j-1][i])
                    return ans;
            }
            ans.append(1, strs[0][i]);
        }
        return ans;
    }
};
