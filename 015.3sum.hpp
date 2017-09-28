class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size() < 3) return ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++) {
            if(i && nums[i] == nums[i-1]) continue;
            for(int j = i + 1, k = nums.size() - 1; j < k;) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0) {
                    vector<int> tmp {nums[i], nums[j], nums[k]};
                    ans.push_back(tmp);
                    while(j < k && nums[j] == nums[j+1]) j++;
                    while(j < k && nums[k] == nums[k-1]) k--;
                    j++; k--;
                } else if(sum > 0){
                    k--;
                } else {
                    j++;
                }
            }
        }
        return ans;
    }
};
