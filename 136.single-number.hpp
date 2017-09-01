class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0;
        for(auto n: nums)
            a ^= n;
        return a;
    }
};
