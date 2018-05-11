class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return {};
        vector<int> index(n);
        vector<string> ans(n);
        iota(index.begin(), index.end(), 0);
        sort(index.begin(), index.end(), [&nums](const int i1, const int i2) {
                return nums[i1] > nums[i2];
            });
        for(int i = 0; i < n; i++) {
            switch(i) {
            case 0:
                ans[index[i]] = "Gold Medal";
                break;
            case 1:
                ans[index[i]] = "Silver Medal";
                break;
            case 2:
                ans[index[i]] = "Bronze Medal";
                break;
            default:
                ans[index[i]] = to_string(i+1);
            }
        }
        return ans;
    }
};
