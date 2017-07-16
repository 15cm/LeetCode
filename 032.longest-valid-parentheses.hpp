#include <algorithm>
#include <stack>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> mStack;
        int accLen = 0;
        int maxLen = 0;
        for(int i = 0; i < s.length(); i ++) {
            if(s[i] == '(') {
                mStack.push(i);
            } else {
                if(mStack.empty()) {
                    accLen = 0;
                } else {
                    int matchPos = mStack.top();
                    mStack.pop();
                    int matchLen = i - matchPos + 1;
                    if(mStack.empty()) {
                        accLen += matchLen;
                        matchLen = accLen;
                    } else {
                        matchLen = i - mStack.top();
                    }
                    maxLen = max(matchLen, maxLen);
                }
            }
        }
        return maxLen;
    }
};
