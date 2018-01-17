class Solution {
    vector<int> nums;
    vector<char> ops;
    vector<vector<vector<int>>> memo;
public:
    vector<int> diffWaysToCompute(string input) {
        if(input.empty()) return vector<int>();
        stringstream ss(input);
        int num;
        char op;
        ss >> num; nums.push_back(num);
        while(ss >> op) {
            ops.push_back(op);
            ss >> num; nums.push_back(num);
        }

        int n = nums.size();
        memo = vector<vector<vector<int>>>(n, vector<vector<int>>(n));

        for(int i = 0; i < n-1; i++) {
            memo[i][i+1].push_back(cal(nums[i], nums[i+1], ops[i]));
        }
        return dfs(0, n-1);
    }

    vector<int> dfs(int l, int r) {
        if(l == r) return vector<int> {nums[l]};
        if(!memo[l][r].empty()) return memo[l][r];
        vector<int> res;
        for(int i = l; i < r; i++) {
            auto tmp = cal(dfs(l, i), dfs(i+1, r), ops[i]);
            res.insert(res.begin(), tmp.begin(), tmp.end());
        }
        return memo[l][r] = res;
    }
    vector<int> cal(const vector<int> &a, const vector<int> &b, char op) {
        vector<int> res;
        for(int x: a) {
            for(int y: b) {
                res.push_back(cal(x, y, op));
            }
        }
        return res;
    }
    int cal(int a, int b, char op) {
        switch(op) {
            case '+': return a+b;
            case '-': return a-b;
            case '*': return a*b;
        }
        return -1;
    }
};
