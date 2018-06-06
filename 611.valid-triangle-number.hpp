class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> path;
        int ans = 0;
        dfs(0, nums, path, ans);
        return ans;
    }
    bool dfs(int p, vector<int> &nums, vector<int> &path, int &ans) {
        int n = nums.size();
        if(path.size() == 3) {
            bool rc = path[0] + path[1] > path[2];
            if(rc) {
                ans++;
            }
            return rc;
        }
        if(p == n) return false;
        for(int i = 0; p + i < n; i++) {
            path.push_back(nums[p + i]);
            bool rc = dfs(p + i + 1, nums, path, ans);
            path.pop_back();
            if(!rc) break;
        }
        return true;
    }
};
