class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = nums[0], cnt = 0;
        for(auto num: nums) {
            if(cnt == 0) {
                cnt++;
                major = num;
            } else {
                if(major == num) cnt++;
                else cnt--;
            }
        }
        return major;
    }
};
