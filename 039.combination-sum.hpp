typedef vector<int> VI;
typedef vector<VI> VVI;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        VVI ans;
        dfs(0, VI(), candidates, target, ans);
        return ans;
    }
    void dfs(int cur, VI path, VI& nums, int target, VVI& ans) {
        if(target == 0) {
            ans.push_back(path);
            return;
        }
        if(cur == nums.size()) return;
        dfs(cur + 1, path, nums, target, ans);
        while((target -= nums[cur]) >= 0) {
            path.push_back(nums[cur]);
            dfs(cur + 1, path, nums, target, ans);
        }
    }
};
