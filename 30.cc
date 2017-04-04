#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while(i >= 0 && nums[i] >= nums[i + 1]) i--;
        if(i >= 0) {
            int j = nums.size() - 1;
            while(j >= 0 && nums[j] <= nums[i]) j--;
            swap(i, j, nums);
        }
        reverseVector(i+1, nums);
    }
    void reverseVector(int s, vector<int>& nums) {
        for(int i = s, j = nums.size() - 1; i < j; i++, j --)
            swap(i, j, nums);
    }
    void swap(int i, int j, vector<int>& vec) {
        int tmp = vec[i];
        vec[i] = vec[j];
        vec[j] = tmp;
    }
};
