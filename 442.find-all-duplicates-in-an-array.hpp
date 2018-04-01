class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] <= 0) continue;
            bool ok = false;
            while(nums[nums[i]-1] > 0) {
                int x = nums[i]-1;
                if(i == x) {
                    nums[i] = -1;
                    ok = true;
                    break;
                }
                swap(nums[i], nums[nums[i]-1]);
                nums[x] = -1;
            }
            if(!ok) {
                nums[nums[i]-1]--;
                nums[i] = 0;
            }
        }
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(nums[i] == -2)
                ans.push_back(i+1);
        }
        return ans;
    }
};
