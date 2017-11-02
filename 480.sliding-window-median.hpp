class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        multiset<int> lo, hi;

        for(int i = 0; i < nums.size(); i++) {
            if(i >= k) {
                int v = nums[i-k];
                if(v <= *lo.rbegin()) {
                    lo.erase(lo.find(v));
                } else {
                    hi.erase(hi.find(v));
                }
            }

            lo.insert(nums[i]);
            hi.insert(*lo.rbegin());
            lo.erase(prev(lo.end()));

            if(lo.size() < hi.size()) {
                lo.insert(*hi.begin());
                hi.erase(hi.begin());
            }

            if(i >= k - 1) {
                ans.push_back(lo.size() > hi.size() ? *lo.rbegin() : ((double)*lo.rbegin() + (double)*hi.begin()) / 2);
            }
        }
        return ans;
    }
};
