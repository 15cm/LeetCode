class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = n*(n+1);
        for(int num: nums) {
            ans -= 2*num;
        }
        return ans/2;
    }
};
