class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for(int i = 0; i < 32; i++) {
            int bitCount = 0;
            for(int num: nums) {
                if(num & (1 << i)) bitCount++;
            }
            ans += bitCount * (n - bitCount);
        }
        return ans;
    }
};
