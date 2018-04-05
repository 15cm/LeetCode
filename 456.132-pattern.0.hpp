class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return false;
        vector<int> minv(n);
        minv[0] = nums[0];
        stack<int> stk;

        for(int i = 1; i < n; i++) minv[i] = min(minv[i-1], nums[i]);
        for(int j = n-1; j > 0; j--) {
            if(nums[j] <= minv[j]) continue;
            while(!stk.empty() && stk.top() < nums[j]) {
                int numk = stk.top(); stk.pop();
                if(numk > minv[j]) return true;
            }
            stk.push(nums[j]);
        }
        return false;
    }
};
