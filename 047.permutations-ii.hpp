class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        if(n == 0) return ans;
        vector<int> path;
        vector<bool> vis(n);
        sort(nums.begin(), nums.end());
        backTrack(nums, path, vis, ans);
        return ans;
    }
    void backTrack(vector<int>& nums, vector<int>& path, vector<bool>& vis, vector<vector<int>>& ans) {
        int n = nums.size();
        if(path.size() == n) {
            ans.push_back(path);
        }

        for(int i = 0; i < n; i++) {
            if(vis[i] || (i > 0 && nums[i] == nums[i-1] && !vis[i-1]))
                continue;
            vis[i] = true;
            path.push_back(nums[i]);
            backTrack(nums, path, vis, ans);
            vis[i] = false;
            path.pop_back();
        }
    }
};
