#include <iostream>
using namespace std;
class Solution {
public:
    bool isNumber(string s) {
        if(s.empty()) return false;
        int p = 0, n = s.length();
        enum State {
            s_begin,
            s_firstDigits,
            s_afterDot,
            s_atExponent,
            s_lastDigits,
            s_end
        };
        State prevState = s_begin;
        State state = s_begin;
        bool shouldCheck = false;
        while(p < n) {
            switch(state) {
            case s_begin:
                if(s[p] == ' ') p++;
                else if(isDigit(s[p])) {
                    state = s_firstDigits;
                }
                else if(isSign(s[p])) {
                    shouldCheck = true;
                    if(p < n - 1 && s[p+1] == '.') {
                        p += 2;
                        state = s_afterDot;
                    } else {
                        state = s_firstDigits;
                        p++;
                    }
                } else if(s[p] == '.') {
                    state = s_afterDot;
                    shouldCheck = true;
                    p++;
                } else {
                    return false;
                }
                break;
            case s_firstDigits:
                prevState = state;
                if(isDigit(s[p])) p++;
                else if(s[p] == 'e') {
                    state = s_atExponent;
                } else if(s[p] == '.') {
                    state = s_afterDot;
                    shouldCheck = true;
                    p++;
                } else if(s[p] == ' ') {
                    state = s_end;
                } else {
                    return false;
                }
                break;
            case s_afterDot:
                prevState = state;
                if(isDigit(s[p])) p++;
                else if(s[p] == 'e') {
                    state = s_atExponent;
                } else if(s[p] == ' ') {
                    state = s_end;
                } else {
                    return false;
                }
                break;
            case s_atExponent:
                prevState = state;
                if(p == n - 1) return false;
                else {
                    p++;
                    if(isSign(s[p])) {
                        shouldCheck = true;
                        state = s_lastDigits;
                        p ++;
                    } else if(isDigit(s[p])) {
                        state = s_lastDigits;
                    } else {
                        return false;
                    }
                }
                break;
            case s_lastDigits:
                prevState = state;
                if(isDigit(s[p])) p++;
                else if(s[p] == ' ') {
                    state = s_end; break;
                } else {
                    return false;
                }
                break;
            case s_end:
                if(s[p] == ' ') p++;
                else return false;
                break;
            };
            if(shouldCheck) {
                switch(state) {
                case s_firstDigits:
                case s_lastDigits:
                    if(p == n || !isDigit(s[p])) return false;
                    break;
                case s_afterDot:
                    if(prevState == s_begin) {
                        if(p == n || !isDigit(s[p])) return false;
                    }
                    break;
                default:
                    break;
                };
                shouldCheck = false;
            }
        }
        return state != s_begin;
    }
    bool isSign(char c) {
        return c == '+' || c == '-';
    }
    bool isDigit(char c) {
        return c >= '0' && c <= '9';
    }
};
