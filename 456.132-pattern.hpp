class Solution {
    vector<int> aux;
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return false;
        int minv = nums[0];
        for(int j = 1; j < n-1; j++) {
            if(nums[j] < minv) {
                minv = nums[j];
                continue;
            }
            for(int k = j+1; k < n; k++) {
                if(nums[k] > minv && nums[k] < nums[j])
                    return true;
            }
        }
        return false;
    }
};
