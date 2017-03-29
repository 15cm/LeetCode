#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n; i ++) {
            if(i == 0 || nums[i] != nums[i - 1]) {
                int c = nums[i];
                for(int l = i + 1, r = n - 1; l < r;) {
                    if(nums[l] + nums[r] < -c) l ++;
                    else if(nums[l] + nums[r] > -c) r -= 1;
                    else {
                        ans.push_back(vector<int> {c, nums[l], nums[r]});
                        l ++;
                        while(nums[l] == nums[l-1]){
                            if(l == r) break;
                            l ++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
