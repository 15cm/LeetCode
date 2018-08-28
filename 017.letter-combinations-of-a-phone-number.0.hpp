class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        unordered_map<char, string> dict {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        queue<string> q;
        q.push("");
        for(int i = 0; i < digits.size(); i++) {
            string &nums = dict[digits[i]];
            int sz = q.size();
            while(sz--) {
                string s = q.front();
                q.pop();
                for(char c: nums) {
                    s.push_back(c);
                    q.push(s);
                    s.pop_back();
                }
            }
        }
        vector<string> ans;
        while(!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};
