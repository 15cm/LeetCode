#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        for(int j = 0; j < nums.size(); i++, j++) {
            while(j < nums.size() && nums[j] == val) j++;
            if(j == nums.size()) break;
            nums[i] = nums[j];
        }
        return i;
    }
};
