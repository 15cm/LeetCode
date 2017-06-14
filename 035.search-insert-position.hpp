#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty()) return 0;
        return binarySearch(0, nums.size() - 1, nums, target);
    }
    int binarySearch(int l, int r, vector<int>& nums, int target) {
        if(l > r) return l;
        int mid = (l + r) / 2;
        int diff = target - nums[mid];
        if(diff < 0) return binarySearch(l, mid - 1, nums, target );
        else if(diff > 0) return binarySearch(mid + 1, r, nums, target );
        else return mid;
    }
};
