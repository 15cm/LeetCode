class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0 || k == 0) return;
        int start = 0, p = 0, cur = nums[p], cnt = 0;
        while(cnt < n) {
            do {
                swap(cur, nums[(p+k)%n]);
                p = (p+k)%n;
                cnt++;
            } while(p != start);
            start++;
            p = start;
            cur = nums[p];
        }
    }
};
