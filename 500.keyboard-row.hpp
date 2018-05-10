class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<vector<int>> rows = {
            {'q','w','e','r','t','y','u','i','o','p'},
            {'a','s','d','f','g','h','j','k','l'},
            {'z','x','c','v','b','n','m'}
        };
        vector<int> mp(26);
        for(int i = 0; i < rows.size(); i++) {
            for(auto c: rows[i]) {
                mp[c - 'a'] = i;
            }
        }
        vector<string> ans;
        for(auto s: words) {
            vector<bool> mark(3);
            for(auto c: s) {
                mark[mp[tolower(c) - 'a']] = true;
            }
            int cnt = 0;
            for(auto m: mark)
                if(m) cnt++;
            if(cnt <= 1) ans.push_back(s);
        }
        return ans;
    }
};
