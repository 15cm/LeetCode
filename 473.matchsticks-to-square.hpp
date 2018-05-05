class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if(nums.size() < 4) return false;
        int sum = 0;
        for(int x: nums) sum += x;
        if(sum % 4 != 0) return false;
        sort(nums.begin(), nums.end(), greater<int>());
        vector<int> sides(4);
        return dfs(0, sides, nums, sum / 4);
    }
    bool dfs(int p, vector<int>& sides, vector<int>& nums, int target) {
        int n = nums.size();
        if(p == n) return true;
        for(int i = 0; i < 4; i++) {
            if(sides[i] + nums[p] > target) continue;
            auto start = sides.begin();
            auto cur = start + i;
            if(find(start, cur, *cur) != cur)
                continue;
            sides[i] += nums[p];
            if(dfs(p+1, sides, nums, target))
                return true;
            sides[i] -= nums[p];
        }
        return false;
    }
};
