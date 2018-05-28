class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        auto c1 = getCoefficient(a), c2 = getCoefficient(b);
        return to_string(c1.first * c2.first - c1.second * c2.second) + "+" + \
            to_string(c1.second * c2.first + c1.first * c2.second) + "i";
    }
    pair<int, int> getCoefficient(const string& s) {
        int opPos = s.find('+');
        return {stoi(s.substr(0, opPos)), stoi(s.substr(opPos + 1, s.size() - (opPos + 1)))};
    }
};
