class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> ans;
        for(int i = 1; i < s.length(); i++) {
            if(s[i-1] == '+' && s[i] == '+') {
                string t = s;
                t[i-1] = t[i] = '-';
                ans.push_back(t);
            }
        }
        return ans;
    }
};
