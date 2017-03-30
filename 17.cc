#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        const vector<string> dict {
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };
        vector<string> ans;
        vector<string> letters;
        if(digits.length() == 0) return ans;
        for(auto& digit: digits) {
            if('2' <= digit && digit <= '9') {
                letters.push_back(dict[digit - '0']);
            } else {
                return ans;
            }
        }
        vector<char> selections(letters.size());
        selectLetter(letters, 0, selections, ans);
        return ans;
    }
    void selectLetter(const vector<string>& letters, int row, vector<char> selections, vector<string>& ans) {
        if(row == letters.size()) {
            string s = "";
            for(auto c: selections) {
                s.append(1, c);
            }
            ans.push_back(s);
            return;
        }
        for(int i = 0; i < letters[row].length(); i ++) {
            selections[row] = letters[row][i];
            selectLetter(letters, row + 1, selections, ans);
        }
    }
};
