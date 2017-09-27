class Solution {
    const char ops[4] = {'+', '-', '*', '.'};
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        if(num.empty()) return ans;
        if(num.length() == 1) {
            if(num[0] - '0' == target) ans.push_back(num);
            return ans;
        }
        string path = string(2*num.length() - 1, '#');
        for(int i = 0; i < path.length(); i++)
            if(!(i & 1)) path[i] = num[i/2];
        dfs(0, path, false, target, ans);
        return ans;
    }
    void dfs(int cur, string& path, bool appending, int target, vector<string>& ans) {
        if(cur == path.length()) {
            if(compute(path) == target) ans.push_back(pathToString(path));
            return;
        }
        if(cur & 1) {
            for(int i = 0; i < 3; i++) {
                if(!(i == 3 && !appending && path[cur-1]  == '0'))
                    path[cur] = ops[i];
                dfs(cur + 1, path, false, target, ans);
            }
            if(appending || path[cur-1] != '0') {
                path[cur] = ops[3];
                dfs(cur + 1, path, true, target, ans);
            }
        } else {
            dfs(cur + 1, path, appending, target, ans);
        }
    }
    long compute(string& path) {
        stack<long> numStack;
        stack<char> opStack;
        for(int i = 0; i < path.length(); i++) {
            if(i & 1) {
                char op = path[i];
                while(!opStack.empty() && getPriority(op) <= getPriority(opStack.top())) {
                    long b = numStack.top(); numStack.pop();
                    long a = numStack.top(); numStack.pop();
                    numStack.push(calculate(a, b, opStack.top()));
                    opStack.pop();
                }
                opStack.push(op);
            } else {
                numStack.push(path[i] - '0');
            }
        }
        while(!opStack.empty()) {
            long b = numStack.top(); numStack.pop();
            long a = numStack.top(); numStack.pop();
            char op = opStack.top(); opStack.pop();
            long c = calculate(a, b, op);
            numStack.push(c);
        }
        return numStack.top();
    }
    int getPriority(char op) {
        switch(op) {
        case '.': return 3;
        case '*': return 2;
        }
        return 1;
    }
    long calculate(long a, long b, char op) {
        switch(op) {
        case '+': return a+b; break;
        case '-': return a-b; break;
        case '*': return a*b; break;
        case '.': return 10*a+b; break;
        }
        return -1;
    }
    string pathToString(string& path) {
        string s;
        for(char c: path) if(c != '.') s.append(1, c);
        return s;
    }
};
