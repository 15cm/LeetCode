class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<int> prevs;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        kSum(0, nums, 4, target, prevs, ans);
        return ans;
    }
    void kSum(int p, vector<int>& nums, int k, int target, vector<int>& prevs, vector<vector<int>>& ans) {
        int n = nums.size();
        if(k == 2) {
            for(int i = p, j = n - 1; i < j;) {
                int sum = nums[i] + nums[j];
                if(sum == target) {
                    prevs.push_back(nums[i]);
                    prevs.push_back(nums[j]);
                    ans.push_back(prevs);
                    prevs.pop_back();
                    prevs.pop_back();
                    while(i < j && nums[i] == nums[i+1]) i++;
                    while(i < j && nums[j] == nums[j-1]) j--;
                    i++; j--;
                } else if(sum < target) {
                    i++;
                } else {
                    j--;
                }
            }
        } else {
            for(int i = p; i <= n - k; i++) {
                if(i != p && nums[i] == nums[i-1])
                    continue;
                prevs.push_back(nums[i]);
                kSum(i + 1, nums, k - 1, target - nums[i], prevs, ans);
                prevs.pop_back();
            }
        }
    }
};
