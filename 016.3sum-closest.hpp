class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int d = numeric_limits<int>::max();
        int ans;
        if(nums.size() < 3) return -1;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++) {
            if(i && nums[i] == nums[i-1]) continue;
            for(int j = i + 1, k = nums.size() - 1; j < k;) {
                int sum = nums[i] + nums[j] + nums[k];
                int diff = sum - target;
                if(diff == 0) return sum;
                else {
                    if(abs(diff) < d) {
                        d = abs(diff);
                        ans = sum;
                    }
                    if(diff > 0) k--;
                    else j++;
                }
            }
        }
        return ans;
    }
};
