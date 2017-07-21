#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 3) return nums.size();
        int i = 0, cnt = 1;
        for(int j = 1; j < nums.size(); j++) {
            if(nums[i] != nums[j]) {
                cnt = 1;
                nums[++i] = nums[j];
            } else {
                if(cnt < 2) {
                    cnt++;
                    nums[++i] = nums[j];
                }
            }
        }
        return i+1;
    }
};
