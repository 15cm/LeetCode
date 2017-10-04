class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 0, n = nums.size();
        while(j < n) {
            while(j < n - 1 && nums[j] == nums[j+1]) j++;
            swap(nums[i++], nums[j++]);
        }
        return i;
    }
};
