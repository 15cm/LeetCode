class Solution {
    vector<int> mp = vector<int>(128);
public:
    vector<string> generatePalindromes(string s) {
        int n = s.length();
        for(char c: s) mp[c]++;
        int mid = -1;
        if(n & 1) {
            for(int c = 0; c < 128; c++) {
                if(mp[c] & 1) {
                    if(mid != -1) {
                        return {};
                    } else {
                        mp[c]--;
                        mid = c;
                    }
                }
            }
        }
        for(int cnt: mp)
            if(cnt & 1)
                return {};
        vector<string> ans;
        string path;
        helper(path, -1, ans, mid, n/2);
        return ans;
    }
    void helper(string& path, int prev, vector<string>& ans, int mid, int len) {
        if(path.length() == len) {
            string tmp = path;
            if(mid != -1) tmp.push_back(mid);
            reverse(tmp.begin(), tmp.end());
            ans.push_back(path + tmp);
            return;
        }
        for(int c = 0; c < 128; c++) {
            if(mp[c] > 0) {
                if(c == prev)
                    continue;
                for(int cnt = mp[c]; cnt > 0; cnt -= 2) {
                    mp[c] -= cnt;
                    path.append(cnt/2, c);
                    helper(path, c, ans, mid, len);
                    mp[c] += cnt;
                    path.erase(path.length() - cnt/2);
                }
            }
        }
    }
};
