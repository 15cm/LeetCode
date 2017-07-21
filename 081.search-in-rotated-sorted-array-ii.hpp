#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty()) return false;
        if(target == nums.front() || target == nums.back()) return true;
        if(target > nums.back() && target < nums.front()) return false;
        bool targetOnLeft = (target > nums.front());
        return binarySearch(nums, 0, nums.size() - 1, target, targetOnLeft);
    }
    bool binarySearch(vector<int>& nums, int left, int right, int target, bool targetOnLeft) {
        if(left > right) return false;
        int mid = (left + right) / 2;
        int diff = target - nums[mid];
        if(diff == 0) return true;
        if(targetOnLeft) {
            if(nums[mid] > nums[left] && diff > 0) return binarySearch(nums, mid + 1, right, target, targetOnLeft);
            else if(nums[mid] == nums[left]) return binarySearch(nums, mid + 1, right, target, targetOnLeft) || binarySearch(nums, left, mid - 1, target, targetOnLeft);
            else return binarySearch(nums, left, mid - 1, target, targetOnLeft);
        } else {
            if(nums[mid] < nums[right] && diff < 0) return binarySearch(nums, left, mid - 1, target, targetOnLeft);
            else if(nums[mid] == nums[right]) return binarySearch(nums, left, mid - 1, target, targetOnLeft) || binarySearch(nums, mid + 1, right, target, targetOnLeft);
            else return binarySearch(nums, mid + 1, right, target, targetOnLeft);
        }
    }
};
