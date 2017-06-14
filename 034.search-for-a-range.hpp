#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = -1, rb = -1;
        if(nums.empty()) return vector<int> {-1, -1};
        binarySearch(0, nums.size() - 1, nums, target, lb, rb);
        return vector<int> {lb, rb};
    }
    void binarySearch(int l, int r, vector<int>& nums, int target, int& leftBound, int& rightBound) {
        if(l > r) return;
        int mid = (l + r) / 2;
        int diff = target - nums[mid];
        if(diff > 0) binarySearch(mid + 1, r, nums, target, leftBound, rightBound);
        else if(diff < 0) binarySearch(l, mid - 1, nums, target, leftBound, rightBound);
        else {
            if(leftBound == -1 || mid < leftBound) leftBound = mid;
            if(rightBound == -1 || mid > rightBound) rightBound = mid;
            binarySearch(l, mid - 1, nums, target, leftBound, rightBound);
            binarySearch(mid + 1, r, nums, target, leftBound, rightBound);
        }
    }
};
