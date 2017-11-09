class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> mp;
        vector<vector<int>> ans;
        int n = words.size();
        for(int i = 0; i < n; i++) mp[words[i]] = i;
        for(int i = 0; i < n; i++) {
            string& word = words[i];
            for(int j = 0; j <= word.length(); j++) {
                string s = word.substr(0, j);
                string t = word.substr(j);
                if(isPalindrome(s)) {
                    string trev = t; reverse(trev.begin(), trev.end());
                    if(mp.count(trev) && mp[trev] != i) {
                        vector<int> tmp = {mp[trev], i};
                        ans.push_back(tmp);
                    }
                }
                if(!t.empty() && isPalindrome(t)) {
                    string srev = s; reverse(srev.begin(), srev.end());
                    if(mp.count(srev) && mp[srev] != i) {
                        vector<int> tmp = {i, mp[srev]};
                        ans.push_back(tmp);
                    }
                }
            }
        }
        return ans;
    }

    bool isPalindrome(string& s) {
        int n = s.length();
        for(int i = 0, j = n - 1; i < j; i++, j--)
            if(s[i] != s[j])
                return false;
        return true;
    }
};
