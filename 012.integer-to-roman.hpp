class Solution {
public:
    char symbols[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    string intToRoman(int num) {
        stack<string> ans;
        int exp = 0;
        while(num > 0) {
            int digit = num % 10;
            ans.push(toRoman(digit, exp++));
            num /= 10;
        }
        string s;
        while(!ans.empty()) {
            s += ans.top(); ans.pop();
        }
        return s;
    }
    string toRoman(int digit, int exp) {
        string s;
        if(exp == 3) {
            s.append(digit, 'M');
        } else {
            int p = exp * 2;
            if(digit == 9) {
                s.append(1, symbols[p]);
                s.append(1, symbols[p + 2]);
            } else if(digit >= 5) {
                s.append(1, symbols[p + 1]);
                s.append(digit - 5, symbols[p]);
            } else if(digit == 4) {
                s.append(1, symbols[p]);
                s.append(1, symbols[p + 1]);
            } else {
                s.append(digit, symbols[p]);
            }
        }
        return s;
    }
}; 
