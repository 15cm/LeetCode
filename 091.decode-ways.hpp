#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int numDecodings(string s) {
        if(s.empty()) return 0;
        vector<int> mp(s.length() + 1, -1);
        return dfs("1", 0, s, mp);
    }
    int dfs(const string &prefix, int cur, string& s, vector<int> &mp) {
        if(prefix[0] == '0') return 0;
        int number = prefix.length() == 1 ? prefix[0] - '0' : 10 * (prefix[0] - '0') + (prefix[1] - '0');
        if(!(number >= 1 && number <= 26)) return 0;
        if(cur == s.length()) return 1;
        if(mp[cur] != -1) return mp[cur];
        return mp[cur] = dfs(s.substr(cur, 1), cur + 1, s, mp) + (cur < s.length() - 1 ? dfs(s.substr(cur, 2), cur + 2, s, mp) : 0);
    }
};
