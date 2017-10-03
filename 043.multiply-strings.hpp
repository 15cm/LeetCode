class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1.empty() || num2.empty()) return "";
        int m = num1.length(), n = num2.length();
        vector<int> f(m + n - 1);
        for(int i = 0; i < m ; i++) {
            for(int j = 0; j < n; j++) {
                f[i+j] += ctoi(num1[i]) * ctoi(num2[j]);
            }
        }
        int end = 0;
        while(end < f.size() && f[end] == 0) end++;
        if(end == f.size()) return "0";
        string s(f.size() - end, 0);

        int carry = 0;
        for(int i = f.size() - 1; i >= end; i--) {
            int num = f[i] + carry;
            s[i] = itoc(num % 10);
            carry = num / 10;
        }
        if(carry > 0) s.insert(s.begin(), itoc(carry));
        return s;
    }
    int ctoi(char c) {
        return c - '0';
    }
    char itoc(int i) {
        return i + '0';
    }
};
