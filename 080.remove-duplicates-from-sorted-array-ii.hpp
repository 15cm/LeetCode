class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 0, n = nums.size();
        while(j < n) {
            while(j + 2 < n && nums[j] == nums[j+2]) j++;
            if(j + 1 < n && nums[j] == nums[j+1]) swap(nums[i++], nums[j++]);
            swap(nums[i++], nums[j++]);
        }
        return i;
    }
};
