#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();
        int prev = 0, cur = 0;
        while(true) {
            cur++;
            while(cur < nums.size() && nums[cur] == nums[cur - 1]) cur++;
            if(cur == nums.size()) return prev + 1;
            prev++;
            nums[prev] = nums[cur];
        }
    }
};
