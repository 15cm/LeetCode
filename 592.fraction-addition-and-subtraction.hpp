int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

struct Frac {
    int num, den;
    Frac() {}
    Frac(int num, int den): num(num), den(den) {}
    void operator += (const Frac &rhs) {
        int g = gcd(den, rhs.den);
        int lfactor = rhs.den / g, rfactor = den / g;
        num = num * lfactor + rhs.num * rfactor;
        den = den * lfactor;
        int newg = gcd(abs(num), den);
        num /= newg;
        den /= newg;
    }
    string toString() {
        return to_string(num) + "/" + to_string(den);
    }
};

class Solution {
public:
    string fractionAddition(string expression) {
        auto &s = expression;
        if(s.empty()) return "";
        int n = s.size();
        Frac sum(0, 1);
        for(int j = 0, i = 1; i <= n; i++) {
            if(i == n || s[i] == '-' || s[i] == '+') {
                int p = s.find('/', j);
                int num = stoi(s.substr(j, p - j));
                int den = stoi(s.substr(p + 1, i - (p + 1)));
                sum += Frac(num, den);
                j = i;
            }
        }
        return sum.toString();
    }
};
