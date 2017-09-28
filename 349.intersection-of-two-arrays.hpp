class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_set<int> rec;
        for(int num: nums1)
            rec.insert(num);
        for(int num: nums2)
            if(rec.count(num)) {
                ans.push_back(num);
                rec.erase(num);
            }
        return ans;
    }
};
