enum Alphabet {
               Space,
               Sign,
               Digit,
               Dot,
               E,
               Invalid
};

class Solution {
public:
    bool isNumber(string s) {
        vector<unordered_map<Alphabet, int>> dfa {
            {},
            {{Space, 1}, {Sign, 2}, {Digit, 3}, {Dot, 4}},
            {{Space, 9}, {Digit, 3}, {Dot, 4}},
            {{Space, 9}, {Digit, 3}, {Dot, 5}, {E, 6}},
            {{Digit, 5}},
            {{Space, 9}, {Digit, 5}, {E, 6}},
            {{Sign, 7}, {Digit, 8}},
            {{Digit, 8}},
            {{Space, 9}, {Digit, 8}},
            {{Space, 9}}
        };
        unordered_set<int> accept_states {
            3, 5, 8, 9
        };

        int state = 1;
        for(char c: s) {
            Alphabet c_type = Invalid;
            if(c == ' ') {
                c_type = Space;
            } else if(c == '+' || c == '-') {
                c_type = Sign;
            } else if(isdigit(c)) {
                c_type = Digit;
            } else if(c == '.') {
                c_type = Dot;
            } else if(c == 'e') {
                c_type = E;
            }
            if(!dfa[state].count(c_type)) {
                return false;
            }
            state = dfa[state][c_type];
        }
        return accept_states.count(state);
    }
};
