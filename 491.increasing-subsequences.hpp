class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(0, path, nums, ans);
        return ans;
    }
    void dfs(int p, vector<int> &path, vector<int> &nums, vector<vector<int>> &ans) {
        if(path.size() >= 2) {
            ans.push_back(path);
        }
        vector<bool> vis(201);
        int n = nums.size();
        for(int i = p; i < n; i++) {
            int key = nums[i] + 100;
            if(vis[key]) continue;
            if(path.empty() || nums[i] >= path.back()) {
                path.push_back(nums[i]);
                dfs(i + 1, path, nums, ans);
                path.pop_back();
                vis[key] = true;
            }
        }
    }
};
