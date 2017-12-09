class Solution {
public:
    string addStrings(string num1, string num2) {
        int n = num1.length(), m = num2.length();
        string s(max(n, m), ' ');
        int carry = 0;
        for(int i = n-1, j = m-1; i >= 0 || j >= 0; i--, j--) {
            int x;
            if(i < 0) {
                x = num2[j] - '0';
            } else if(j < 0) {
                x = num1[i] - '0';
            } else {
                x = num1[i] - '0' + num2[j] - '0';
            }
            x += carry;
            carry = x / 10;
            x %= 10;
            s[max(i, j)] = x + '0';
        }
        if(carry > 0) {
            s.insert(s.begin(), carry + '0');
        }
        return s;
    }
};
