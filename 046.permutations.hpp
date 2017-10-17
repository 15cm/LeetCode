class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        if(n == 0) return ans;
        vector<int> path;
        helper(nums, path, ans);
        return ans;
    }
    void helper(vector<int>& nums, vector<int>& path, vector<vector<int>>& ans) {
        int n = nums.size();
        if(path.size() == n) {
            ans.push_back(path);
        }
        for(int i = 0; i < n; i++) {
            if(find(path.begin(), path.end(), nums[i]) != path.end()) continue;
            path.push_back(nums[i]);
            helper(nums, path, ans);
            path.pop_back();
        }
    }
};
