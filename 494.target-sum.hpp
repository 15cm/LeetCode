typedef vector<int> VI;
typedef vector<VI> VVI;
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        VVI memo(nums.size(), VI(2001, INT_MIN));
        return dfs(0, nums, 0, S, memo);
    }
    int dfs(int p, VI& nums, int sum, int target, VVI& memo) {
        int n = nums.size();
        if(p == n) {
            return sum == target ? 1 : 0;
        }
        int idx = sum + 1000;
        if(memo[p][idx] != INT_MIN) return memo[p][idx];
        int addChoices = dfs(p + 1, nums, sum + nums[p], target, memo);
        int subtractChoices = dfs(p + 1, nums, sum - nums[p], target, memo);
        return memo[p][idx] = addChoices + subtractChoices;
    }
};
