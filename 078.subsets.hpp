#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        for(int s = 0; s < (1 << nums.size()); s++) {
            vector<int> subset;
            for(int i = 0; i < nums.size(); i++) {
                if(s & (1 << i)) subset.push_back(nums[i]);
            }
            ans.push_back(subset);
        }
        return ans;
    }
};
