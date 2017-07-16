#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> seq(nums.size());
        vector<vector<int>> ans;
        if(nums.size() == 0) return ans;
        sort(nums.begin(), nums.end());
        dfs(seq, 0, nums, ans);
        return ans;
    }
    void dfs(vector<int>& seq, int cur, vector<int>& nums, vector<vector<int>>& ans) {
        if(cur == nums.size()) {
            ans.push_back(seq);
        }
        for(int i = 0; i < nums.size(); i ++) {
            if(i == 0 || nums[i] != nums[i-1]) {
                int c1 = 0, c2 = 0;
                for(int j = 0; j < cur; j ++) if(seq[j] == nums[i]) c1++;
                for(auto& num: nums) if(num == nums[i]) c2++;
                if(c1 < c2) {
                    seq[cur] = nums[i];
                    dfs(seq, cur + 1, nums, ans);
                }
            }
        }
    }
};
