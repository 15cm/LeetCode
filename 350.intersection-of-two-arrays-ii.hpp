class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int, int> mp;
        for(int num: nums1) mp[num]++;
        for(int num: nums2)
            if(mp[num]-- > 0)
                ans.push_back(num);
        return ans;
    }
};
