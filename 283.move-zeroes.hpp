class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int i = 0, j = 0; j < nums.size(); j++)
            if(nums[j])
                swap(nums, i++, j);
    }
    void swap(vector<int>& nums, int i, int j) {
        int t = nums[i]; nums[i] = nums[j]; nums[j] = t;
    }
};
