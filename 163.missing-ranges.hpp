class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ans;
        for(int i = 0; i <= nums.size(); i++) {
            long left = i == 0 ? lower : (long)nums[i-1] + 1;
            long right = i == nums.size() ? upper : (long)nums[i] - 1;
            if(left < right) {
                ans.push_back(to_string(left) + "->" + to_string(right));
            } else if(left == right) {
                ans.push_back(to_string(left));
            }
        }
        return ans;
    }
};
