class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(int x: nums) sum += x;
        if(sum % k != 0) return false;
        int target = sum / k;
        sort(nums.begin(), nums.end());
        int p = nums.size() - 1;
        while(nums[p] == target) {
            p--;
            k--;
        }
        vector<int> groups(k);
        return search(p, nums, groups, target);
    }
    bool search(int p, vector<int>& nums, vector<int>& groups, int target) {
        if(p < 0) return true;
        int v = nums[p--];
        for(int i = 0; i < groups.size(); i++) {
            if(groups[i] + v <= target) {
                groups[i] += v;
                if(search(p, nums, groups, target))
                    return true;
                groups[i] -= v;
            }
            if(groups[i] == 0) break;
        }
        return false;
    }
};
