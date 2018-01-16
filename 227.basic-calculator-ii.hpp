class Solution {
public:
    int calculate(string s) {
        stringstream ss(s);
        char op;
        int num;
        stack<int> nums, ops;
        while(ss.rdbuf()->in_avail()) {
            char x = ss.peek();
            if(x == ' ') {
                ss.ignore();
            } else if('0' <= x && x <= '9') {
                ss >> num;
                nums.push(num);
            } else {
                ss >> op;
                while(!ops.empty() && rank(ops.top()) >= rank(op)) {
                    char tmpOp = ops.top(); ops.pop();
                    int b = nums.top(); nums.pop();
                    int a = nums.top(); nums.pop();
                    nums.push(compute(a, b, tmpOp));
                }
                ops.push(op);
            }
        }
        while(!ops.empty()) {
            char tmpOp = ops.top(); ops.pop();
            int b = nums.top(); nums.pop();
            int a = nums.top(); nums.pop();
            nums.push(compute(a, b, tmpOp));
        }
        if(!nums.empty()) {
            return nums.top();
        }
        return -1;
    }
    int rank(char op) {
        switch(op) {
            case '+':
            case '-':
                return 0;
            case '*':
            case '/':
                return 1;
        }
        return -1;
    }
    int compute(int a, int b, char op) {
        switch(op) {
            case '+':
                return a+b;
            case '-':
                return a-b;
            case '*':
                return a*b;
            case '/':
                return a/b;
        }
        return -1;
    }
};
