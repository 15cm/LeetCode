class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> path, ans;
        vector<int> memo(nums.size());
        dfs(0, nums, path, ans, memo);
        return ans;
    }
    void dfs(int p, vector<int>& nums, vector<int>& path, vector<int>& ans, vector<int>& memo) {
        int n = nums.size();
        if(path.size() > ans.size()) {
            ans = path;
        }
        if(p == n) return;
        for(int i = p; i < n; i++) {
            if(!path.empty() && nums[i] % path.back() != 0 || memo[i] > path.size())
                continue;
            path.push_back(nums[i]);
            memo[i] = max(memo[i], (int)path.size());
            dfs(i+1, nums, path, ans, memo);
            path.pop_back();
        }
    }
};
