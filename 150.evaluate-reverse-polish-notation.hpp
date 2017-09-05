class Solution {
public:
    stack<int> s;
    const unordered_set<char> ops{'+', '-', '*', '/'};
    int evalRPN(vector<string>& tokens) {
        for(const auto& token: tokens) {
            if(token.length() == 1 && ops.count(token[0]))
                calculate(token[0]);
            else
                s.push(stoi(token));
        }
        if(!s.empty()) return s.top();
        else return -1;
    }
    void calculate(char op) {
        int rhs = s.top(); s.pop();
        int lhs = s.top(); s.pop();
        int ans;
        switch(op) {
        case '+':
            ans = lhs + rhs;
            break;
        case '-':
            ans = lhs - rhs;
            break;
        case '*':
            ans = lhs * rhs;
            break;
        case '/':
            if(rhs == 0) ans = 0;
            ans = lhs / rhs;
            break;
        }
        s.push(ans);
    }
};
