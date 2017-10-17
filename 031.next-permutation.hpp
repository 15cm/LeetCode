class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return;
        int i = n - 2;
        while(i >= 0 && nums[i] >= nums[i+1]) i--;
        if(i >= 0) {
            int j = n - 1;
            while(j >= i && nums[j] <= nums[i]) j--;
            swap(nums[i], nums[j]);
        }
        auto it = nums.begin();
        advance(it, i + 1);
        reverse(it, nums.end());
    }
};
