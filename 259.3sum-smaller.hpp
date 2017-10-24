class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int cnt = 0;
        int n = nums.size();
        for(int i = 0; i < n - 2; i++) {
            int t = target - nums[i];
            for(int j = i + 1, k = n - 1; j < k;) {
                int sum = nums[j] + nums[k];
                if(sum < t) {
                    cnt += k - j;
                    j++;
                } else {
                    k--;
                }
            }
        }
        return cnt;
    }
};
