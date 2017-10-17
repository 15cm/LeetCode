class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        sort(nums.begin(), nums.end());
        backTrack(0, nums, path, ans);
        return ans;
    }
    void backTrack(int p, vector<int>& nums, vector<int>& path, vector<vector<int>>& ans) {
        ans.push_back(path);
        for(int i = p; i < nums.size(); i++) {
            if(i > p && nums[i] == nums[i-1]) continue;
            path.push_back(nums[i]);
            backTrack(i + 1, nums, path, ans);
            path.pop_back();
        }
    }
};
