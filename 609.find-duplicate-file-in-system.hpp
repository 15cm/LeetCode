class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> mp;
        for(auto &path: paths) {
            int p = path.find(' ');
            auto dir = path.substr(0, p);
            for(int q = path.find('(', p), r = path.find(')', q);
                r != string::npos;
                p = r + 1, q = path.find('(', r), r = path.find(')', q)) {
                auto fname = path.substr(p + 1, q - (p + 1));
                auto content = path.substr(q + 1, r - (q + 1));
                mp[content].emplace_back(dir + "/" + fname);
            }
        }
        vector<vector<string>> ans;
        for(auto &pr: mp) {
            if(pr.second.size() > 1) {
                ans.push_back(pr.second);
            }
        }
        return ans;
    }
};
