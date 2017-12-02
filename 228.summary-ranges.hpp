class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();
        for(int i = 0, j; i < n; i = j) {
            for(j = i + 1; j < n && nums[j] == nums[j-1] + 1; j++);
            int k = j - 1;
            if(i == k) {
                ans.push_back(to_string(nums[i]));
            } else {
                ans.push_back(to_string(nums[i]) + "->" + to_string(nums[k]));
            }
        }
        return ans;
    }
};
