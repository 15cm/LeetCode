class Solution {
public:
    string solveEquation(string equation) {
        int pos = equation.find('=');
        auto lpr = parse(equation.substr(0, pos + 1)),
            rpr = parse(equation.substr(pos + 1) + "=");
        int coe = lpr.first - rpr.first, con = rpr.second - lpr.second;
        if(coe == 0) {
            if(con == 0) return "Infinite solutions";
            else return "No solution";
        } else {
            return "x=" + to_string(con / coe);
        }
    }
    pair<int, int> parse(const string &s) {
        string acc;
        int coe = 0, con = 0;
        for(auto c: s) {
            switch(c) {
            case '+':
            case '-':
            case '=':
                if(!acc.empty()) {
                    if(acc.back() == 'x') {
                        acc.pop_back();
                        if(acc.empty() || acc.back() == '+') {
                            coe++;
                        } else if(acc.back() == '-') {
                            coe--;
                        } else {
                            coe += stoi(acc);
                        }
                    } else {
                        con += stoi(acc);
                    }
                    acc.clear();
                }
            default:
                acc.push_back(c);
            }
        }
        return {coe, con};
    }
};
