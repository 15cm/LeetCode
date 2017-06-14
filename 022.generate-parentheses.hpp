#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "(";
        if(n == 0) return ans;
        int leftInStack = 1;
        search(ans, s, leftInStack, n-1, n);
        return ans;
    }
    void search(vector<string>& ans, string s, int leftInStack, int numOfLeft, int numOfRight) {
        if(numOfLeft == 0 && numOfRight == 0) ans.push_back(s);
        if(numOfLeft > 0) {
            // Left
            int leftInStackNew = leftInStack + 1;
            int numOfLeftNew =  numOfLeft - 1;
            string sNew = s + "(";
            search(ans, sNew, leftInStackNew, numOfLeftNew, numOfRight);
        }
        if(leftInStack > 0) {
            // Right
            s.append(1, ')');
            search(ans, s, leftInStack - 1, numOfLeft, numOfRight - 1 );
        }
    }
};
