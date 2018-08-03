class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) continue;
            bool dir = (nums[i] > 0);
            int j = ((i + nums[i] % n) + n) % n;
            if(j == i) continue;
            nums[i] = 0;
            while(true) {
                if(j == i) return true;
                if(nums[j] == 0 || (nums[j] > 0) != dir) break;
                int k = ((j + nums[j] % n) + n) % n;
                nums[j] = 0;
                j = k;
            }
        }
        return false;
    }
};
