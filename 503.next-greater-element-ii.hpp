class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return {};
        vector<int> ans(n, -1);
        stack<int> stk;
        for(int i = 0; i < 2 * n; i++) {
            while(!stk.empty() && nums[i % n] > nums[stk.top() % n]) {
                int j = stk.top(); stk.pop();
                if(j < n)
                    ans[j] = nums[i % n];
            }
            stk.push(i);
        }
        return ans;
    }
};
