class Solution {
public:
    vector<int> nums;
    Solution(vector<int> nums) {
        this->nums = nums;
    }
    
    int pick(int target) {
        int cnt = 0, ans = -1;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == target) {
                if(rand() % ++cnt == 0) ans = i;
            }
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
