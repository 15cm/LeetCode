class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        int maxn= n - k;
        vector<char> stk(n);
        int top = 0;
        for(auto c: num) {
            while(top > 0 && k > 0 && stk[top-1] > c) {
                top--;
                k--;
            }
            stk[top++] = c;
        }

        top = min(top, maxn);
        int i = 0;
        for(; i < top && stk[i] == '0'; i++);
        return i == top ? "0" : string(stk.begin() + i, stk.begin() + top);
    }
};
