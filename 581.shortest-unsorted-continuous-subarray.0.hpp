class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = n, right = -1;
        stack<int> stk;
        for(int i = 0; i < n; i++) {
            while(!stk.empty() && nums[stk.top()] > nums[i]) {
                left = min(left, stk.top()); stk.pop();
            }
            stk.push(i);
        }
        stk = stack<int>();
        for(int i = n - 1; i >= 0; i--) {
            while(!stk.empty() && nums[stk.top()] < nums[i]) {
                right = max(right, stk.top()); stk.pop();
            }
            stk.push(i);
        }
        return max(0, right - left + 1);
    }
};
