class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        vector<int> ans;
        for(int n: nums1) {
            mp[n]++;
        }
        for(int n: nums2) {
            if(mp[n]-- > 0)
                ans.push_back(n);
        }
        return ans;
    }
};
