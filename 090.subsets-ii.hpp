typedef vector<int> VI;
typedef vector<VI> VVI;
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        VVI ans = {{}};
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n;) {
            int cnt = 0;
            while(i + cnt < n && nums[i + cnt] == nums[i]) cnt++;
            int previousN = ans.size();
            for(int j = 0; j < previousN; j++) {
                VI subset = ans[j];
                for(int k = 0; k < cnt; k++) {
                    subset.push_back(nums[i]);
                    ans.push_back(subset);
                }
            }
            i += cnt;
        }
        return ans;
    }
};
