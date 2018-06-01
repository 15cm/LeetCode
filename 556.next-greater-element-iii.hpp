class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> nums;
        while(n) {
            nums.push_back(n % 10);
            n /= 10;
        }
        reverse(nums.begin(), nums.end());
        bool ok = nextPermutation(nums);
        if(!ok) return -1;
        long ans = 0;
        for(int x: nums) {
            ans *= 10;
            ans += x;
        }
        if(ans > INT_MAX) return -1;
        return ans;
    }
    bool nextPermutation(vector<int> &nums) {
        int n = nums.size();
        int i = n - 1;
        while(i > 0 && nums[i-1] >= nums[i]) {
            i--;
        }
        if(i == 0) return false;
        auto it = upper_bound(nums.rbegin(), nums.rbegin() + (n - i), nums[i-1]);
        swap(nums[i-1], *it);
        reverse(nums.begin() + i, nums.end());
        return true;
    }
};
