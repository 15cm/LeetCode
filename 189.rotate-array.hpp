class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        auto left = nums.begin(), right = nums.end(), mid = right - (k % nums.size());
        reverse(left, mid);
        reverse(mid, right);
        reverse(left, right);
    }
};
