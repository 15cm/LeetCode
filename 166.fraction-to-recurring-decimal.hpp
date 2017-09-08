class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long n = numerator, d = denominator;
        if(n % d == 0) return to_string(n / d);
        bool neg = false;
        if(n < 0) {
            n = -n;
            if(d > 0)
                neg = true;
            else
                d = -d;
        } else {
            if(d < 0) {
                d = -d;
                neg = true;
            }
        }
        int exp = 0;
        unordered_map<int, int> mark;
        int repeatBegin = -1, repeatEnd = -1;
        list<string> l;
        while(n) {
            if(mark.count(n)) {
                repeatBegin = mark[n];
                repeatEnd = exp - 1;
                if(repeatBegin == 0) {
                    repeatBegin++;
                    repeatEnd++;
                    l.push_back(to_string(n / d));
                }
                break;
            }
            mark[n] = exp++;
            if(n < d) {
                l.push_back("0");
            } else {
                l.push_back(to_string(n / d));
                n %= d;
            }
            n *= 10;
        }
        string s = neg ? "-" : "";
        int i = 0;
        for(auto digit: l) {
            if(i == 1) s += ".";
            if(i == repeatBegin) s += "(";
            s += digit;
            if(i == repeatEnd) s += ")";
            i++;
        }
        return s;
    }
};
