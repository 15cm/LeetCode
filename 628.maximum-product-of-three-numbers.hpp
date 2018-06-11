class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        priority_queue<int> low;
        priority_queue<int, vector<int>, greater<int>> high;
        for(int x: nums) {
            if(high.size() < 3) {
                high.push(x);
            } else if(x > high.top()) {
                high.pop();
                high.push(x);
            }
            if(low.size() < 2) {
                low.push(x);
            } else if(x < low.top()) {
                low.pop();
                low.push(x);
            }
        }
        vector<int> lo, hi;
        while(!low.empty()) {
            lo.push_back(low.top());
            low.pop();
        }
        while(!high.empty()) {
            hi.push_back(high.top());
            high.pop();
        }
        reverse(lo.begin(), lo.end());
        reverse(hi.begin(), hi.end());
        int m = lo.size(), n = hi.size();
        int ans = productOf(hi, 3);
        if(m >= 2 && lo[1] < 0) {
            ans = max(ans, productOf(lo, 2) * hi[0]);
        }
        return ans;
    }
    int productOf(vector<int> &nums, int k) {
        int res = 1;
        for(int i = 0; i < k && i < nums.size(); i++) {
            res *= nums[i];
        }
        return res;
    }
};
