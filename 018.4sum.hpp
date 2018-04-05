#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        if(nums.size() < 4) return ans;
        for(int i = 0; i < nums.size() - 3; i ++)
            if(i == 0 || nums[i] != nums[i-1])
                threeSum(nums, i, target - nums[i], ans);
        return ans;
    }
    void threeSum(vector<int>& nums, int cur, int target, vector<vector<int>>& ans) {
        for(int i = cur + 1; i < nums.size() - 2; i ++) {
            if(i == cur + 1 || nums[i] != nums[i-1]) {
                int t = target - nums[i];
                for(int j = i + 1, k = nums.size() - 1; j < k;) {
                    int res = t - nums[j] - nums[k];
                    if(res > 0) j++;
                    else if(res < 0)k--;
                    else {
                        ans.push_back(vector<int> {nums[cur], nums[i], nums[j], nums[k]});
                        j++;
                        while(j < k && nums[j] == nums[j-1]) j++;
                    }
                }
            }
        }
    }
};
