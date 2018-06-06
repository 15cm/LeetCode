class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = upper_bound(nums.begin(), nums.end(), 0) - nums.begin(); i < n - 2; i++) {
            for(int j = i + 1, k = i + 2; j < n - 1; j++) {
                if(k == n) {
                    ans += (k - j - 1) * (k - j) / 2;
                    break;
                }
                while(k < n && nums[i] + nums[j] > nums[k]) k++;
                ans += k - j - 1;
            }
        }
        return ans;
    }
};
