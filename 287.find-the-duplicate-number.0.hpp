class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int p1, p2;
        p1 = p2 = nums[0];
        do {
            p1 = forward(p1, 1, nums), p2 = forward(p2, 2, nums);
        } while(p1 != p2);
        for(p1 = nums[0]; p1 != p2; p1 = forward(p1, 1, nums), p2 = forward(p2, 1, nums));
        return p1;
    }
    int forward(int p, int times, vector<int>& nums) {
        while(times--) {
            p = nums[p];
        }
        return p;
    }
};
