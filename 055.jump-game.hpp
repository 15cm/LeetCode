#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.empty()) return true;
        return dfs(0, nums);
    }
    bool dfs(int cur, vector<int>& nums) {
        int maxJump = nums[cur];
        if(cur + maxJump >= nums.size() - 1) return true;
        for(int i = 1; i <= maxJump; i ++) {
            if(i + nums[cur + i] > maxJump && dfs(cur + i, nums)) return true;
        }
        return false;
    }
};
