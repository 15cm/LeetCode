#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;
        bool targetOnGroupLeft = target >= nums[0] ? true : false;
        return binarySearch(0, nums.size() - 1, nums, target, targetOnGroupLeft);
    }
    int binarySearch(int l, int r, vector<int>& nums, int target, bool targetOnGroupLeft) {
        if(l > r) return -1;
        int mid = (l + r) / 2;
        int valOfMid = nums[mid];
        bool midOnGroupLeft = valOfMid >= nums[0] ? true : false;
        int diff = target - valOfMid;
        if(diff == 0) return mid;
        if(targetOnGroupLeft) {
            if(midOnGroupLeft && diff > 0) return binarySearch(mid + 1, r, nums, target, targetOnGroupLeft);
            else return binarySearch(l, mid - 1, nums, target, targetOnGroupLeft);
        } else {
            if(!midOnGroupLeft && diff < 0) return binarySearch(l, mid - 1, nums, target, targetOnGroupLeft);
            else return binarySearch(mid + 1, r, nums, target, targetOnGroupLeft);
        }
    }
};
