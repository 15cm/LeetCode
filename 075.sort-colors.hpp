#include <vector>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.size() < 2) return;
        int i = 0, j = 0, k = nums.size() - 1;
        while(j <= k) {
            switch(nums[j]) {
            case 0:
                if(i == j) j ++;
                else swap(nums, i, j);
                i++;
                break;
            case 1:
                j++;
                break;
            case 2:
                swap(nums, j, k);
                k--;
                break;
            }
        }
    }
    void swap(vector<int>& a, int i, int j) {
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
};
