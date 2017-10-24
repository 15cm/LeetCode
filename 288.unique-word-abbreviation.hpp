class ValidWordAbbr {
    unordered_map<string, unordered_map<int, unordered_set<string>>> mp;
public:
    ValidWordAbbr(vector<string> dictionary) {
        for(string& s: dictionary) {
            if(s.length() <= 2) {
                mp[s][0].insert(s);
            } else {
                string t;
                t.push_back(s[0]);
                t.push_back(s.back());
                mp[t][s.length() - 2].insert(s);
            }
        }
    }
    
    bool isUnique(string word) {
        int len = word.length();
        if(len <= 2) {
            return !mp.count(word) || onlyOneinSet(word, mp[word][0]);
        } else {
            string t;
            t.push_back(word[0]);
            t.push_back(word.back());
            return !mp.count(t) || !mp[t].count(len - 2) || onlyOneinSet(word, mp[t][len-2]);
        }
    }
    bool onlyOneinSet(string& s, unordered_set<string>& l) {
        return l.size() == 1 && *l.begin() == s;
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj.isUnique(word);
 */
