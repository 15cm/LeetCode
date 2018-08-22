#define LL long long
class Solution {
    stack<LL> nums;
    stack<char> ops;
public:
    int calculate(string s) {
        int n = s.size();
        int i = 0;
        while(true) {
            while(i < n && s[i] == ' ') i++;
            if(i == n) break;
            if(isdigit(s[i])) {
                int j = i + 1;
                while(j < n && isdigit(s[j])) j++;
                nums.push(stol(s.substr(i, j - i)));
                i = j;
            } else {
                if(s[i] == '('){
                    ops.push('(');
                } else if(s[i] == ')') {
                    while(ops.top() != '(') {
                        eval();
                    }
                    ops.pop();
                } else {
                    while(!ops.empty() && prec(ops.top()) >= prec(s[i])) {
                        eval();
                    }
                    ops.push(s[i]);
                }
                i++;
            }
        }
        while(!ops.empty()) {
            eval();
        }
        return nums.top();
    }
    void eval() {
        LL b = nums.top();
        nums.pop();
        LL a = nums.top();
        nums.pop();
        char op = ops.top();
        ops.pop();
        nums.push(calculate(a, b, op));
    }
    LL calculate(LL a, LL b, char op) {
        switch(op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        }
        return INT_MAX;
    }
    int prec(char c) {
        switch(c) {
        case '(':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        }
        return -1;
    }
};
