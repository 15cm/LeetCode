class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int axorb = 0;
        for(int num: nums) {
            axorb ^= num;
        }
        int bitFilter = axorb & (-axorb);
        int left = 0, right = 0;
        for(int num: nums) {
            if(num & bitFilter) {
                left ^= num;
            } else {
                right ^= num;
            }
        }
        return {left, right};
    }
};
