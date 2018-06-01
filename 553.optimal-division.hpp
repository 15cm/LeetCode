class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        if(nums.empty()) return "";
        vector<pair<int, int>> path;
        pair<double, vector<pair<int, int>>> ans;
        dfs(0, 0, path, ans, nums);
        string s;
        for(auto& pr: ans.second) {
            if(pr.first == pr.second) {
                s += to_string(nums[pr.first]);
            } else {
                string t = "(";
                for(int i = pr.first; i <= pr.second; i++) {
                    t += to_string(nums[i]);
                    t.push_back('/');
                }
                t.pop_back();
                t.push_back(')');
                s += t;
            }
            s.push_back('/');
        }
        s.pop_back();
        return s;
    }
    void dfs(int p, double acc, vector<pair<int, int>> &path, pair<double, vector<pair<int, int>>> &ans, vector<int>& nums) {
        int n = nums.size();
        if(p == n) {
            if(acc > ans.first) {
                ans.first = acc;
                ans.second = path;
            }
            return;
        }
        double div;
        for(int i = 0; p + i < n; i++) {
            path.push_back({p, p + i});
            if(i == 0) {
                div = nums[p + i];
            } else {
                div /= nums[p + i];
            }
            double tmp = (p == 0 ? div : acc / div);
            dfs(p + i + 1, tmp, path, ans, nums);
            path.pop_back();
        }
    }
};
