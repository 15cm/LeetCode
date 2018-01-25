class Solution {
    const vector<pair<char, char>> pairs = {{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
public:
    int strobogrammaticInRange(string low, string high) {
        int ans = 0;
        for(int l = low.length(); l <= high.length(); l++) {
            string s = string(l, ' ');
            dfs(s, 0, l-1, low, high, ans);
        }
        return ans;
    }
    void dfs(string& s, int left, int right, const string& low, const string& high, int &cnt) {
        if(left > right) {
            if(s.length() == low.length() && s < low || s.length() == high.length() && s > high)
                return;
            cnt++;
            return;
        }
        for(auto& pr: pairs) {
            if(left == 0 && s.length() > 1 && pr.first == '0' || left == right && pr.first != pr.second) continue;
            s[left] = pr.first;
            s[right] = pr.second;
            dfs(s, left+1, right-1, low, high, cnt);
        }
    }
};
