class Solution {
public:
    int calculate(string s) {
        stack<long> nums;
        stack<char> ops;
        long num = 0;
        bool hasNum = false;
        for(char c: s) {
            if(c >= '0' && c <= '9') {
                hasNum = true;
                num = num*10 + c - '0';
            } else {
                if(hasNum) {
                    nums.push(num);
                    num = 0;
                    hasNum = false;
                }
                if(c == '(') {
                    ops.push(c);
                } else if(c == ')') {
                    while(ops.top() != '(') {
                        long b = nums.top(); nums.pop();
                        long a = nums.top(); nums.pop();
                        char op = ops.top(); ops.pop();
                        nums.push(compute(a, b, op));
                    }
                    ops.pop();
                } else if(c == '+' || c == '-') {
                    while(!ops.empty() && ops.top() != '(') {
                        long b = nums.top(); nums.pop();
                        long a = nums.top(); nums.pop();
                        char op = ops.top(); ops.pop();
                        nums.push(compute(a, b, op));
                    }
                    ops.push(c);
                }
            }
        }
        if(hasNum) {
            nums.push(num);
            num = 0;
            hasNum = false;
        }
        while(!ops.empty()) {
            long b = nums.top(); nums.pop();
            long a = nums.top(); nums.pop();
            char op = ops.top(); ops.pop();
            nums.push(compute(a, b, op));
        }
        return nums.top();
    }
    long compute(long a, long b, char op) {
        switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        }
    }
};
