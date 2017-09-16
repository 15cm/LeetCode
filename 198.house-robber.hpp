class Solution {
public:
    int rob(vector<int>& nums) {
        int prevNo, prevYes;
        prevNo = prevYes = 0;
        for(auto n: nums) {
            int tmp = prevNo;
            prevNo = max(prevNo, prevYes);
            prevYes = n + tmp;
        }
        return max(prevNo, prevYes);
    }
};
