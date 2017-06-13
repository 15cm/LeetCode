#include <iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string S[numRows];
        bool isZig = false;
        int row = 0;
        if(numRows <= 1) return s;
        if(numRows == 2) {
            string ans;
            for(int i = 0; i < s.length(); i += 2)
                ans.append(1, s[i]);
            for(int i = 1; i < s.length(); i += 2)
                ans.append(1, s[i]);
            return ans;
        }
        for(int i = 0; i < s.length(); i ++) {
            S[row].append(1, s[i]);
            if(!isZig) {
                if(row == numRows - 1) {
                    isZig = true;
                    row--;
                } else {
                    row++;
                }
            } else {
                if(row == 1) isZig = false;
                row--;
            }
        }
        string ans;
        for(auto& l: S)
            for(auto& c: l)
                ans.append(1, c);
        return ans;
    }
};
