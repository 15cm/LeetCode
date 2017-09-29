class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        deque<int> q;
        for(int i = 0; i < n; i++) {
            int left = i - k + 1;
            while(!q.empty() && q.front() < left) q.pop_front();
            while(!q.empty() && nums[q.back()] < nums[i]) q.pop_back();
            q.push_back(i);
            if(left >= 0) {
                ans.push_back(nums[q.front()]);
            }
        }
        return ans;
    }
};
