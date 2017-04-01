#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(auto& c: s) {
            if(c == '(' || c == '[' || c == '{') stk.push(c);
            else if(c == ')' || c == ']' || c == '}'){
                if(stk.empty()) return false;
                char prev = stk.top();
                stk.pop();
                switch(c) {
                case ')': if(prev != '(') return false; break;
                case ']': if(prev != '[') return false; break;
                case '}': if(prev != '{') return false; break;
                }
            } else {
                return false;
            }
        }
        return stk.empty();
    }
};
