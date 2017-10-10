class Solution {
public:
    bool isNumber(string s) {
        int n = s.length();
        int i = 0;
        while(i < n && s[i] == ' ') i++;
        if(i == n) return false;
        if(s[i] == '+' || s[i] == '-') i++;
        int n_digit, n_point;
        for(n_digit = 0, n_point = 0; i < n && (s[i] >= '0' && s[i] <= '9' || s[i] == '.'); i++) {
            if(s[i] == '.') n_point++;
            else n_digit++;
        }
        if(n_point > 1 || n_digit < 1)
            return false;
        if(i == n)
            return true;
        if(s[i] == 'e') {
            i++;
            if(i == n) return false;
            if(s[i] == '+' || s[i] == '-') i++;
            int n_digit;
            for(n_digit = 0; i < n && (s[i] >= '0' && s[i] <= '9'); i++, n_digit++);
            if(n_digit < 1)
                return false;
        }
        while(i < n && s[i] == ' ') i++;
        return i == n;
    }
};
