class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] == -1 || nums[i] == i + 1) continue;
            while(!(nums[i] == -1 || nums[i] == i + 1)) {
                if(nums[i] == nums[nums[i] - 1]) {
                    ans.push_back(nums[i]);
                    nums[i] = -1;
                    break;
                }
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for(int i = 0; i < n; i++) {
            if(nums[i] == -1) ans.push_back(i + 1);
        }
        return ans;
    }
};
