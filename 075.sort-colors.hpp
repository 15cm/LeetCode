class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1, i = 0;;
        while(i <= hi) {
            if(nums[i] == 0) swap(lo++, i++, nums);
            else if(nums[i] == 2) swap(hi--, i, nums);
            else i++;
        }
    }
    void swap(int i, int j, vector<int>& a) {
        int t = a[i]; a[i] = a[j]; a[j] = t;
    }
};
