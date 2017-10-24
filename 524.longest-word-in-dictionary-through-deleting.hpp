class Solution {
    unordered_set<string> memo;
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(), [](const string& lhs, const string& rhs) {
                return lhs.length() > rhs.length() || lhs.length() == rhs.length() && lhs < rhs;
            });
        for(string& t: d) {
            if(isValid(s, t))
                return t;
        }
        return "";
    }
    bool isValid(string& s, string& t) {
        int i = 0, j = 0;
        while(i < s.length() && j < t.length()) {
            if(s[i++] == t[j])
                j++;
        }
        return j == t.length();
    }
};
