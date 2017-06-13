#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // a + b + c -> k
        sort(nums.begin(), nums.end());
        int diff = 0x7FFFFFFF; // k - a - b - c
        int ans;
        for(int i = 0; i < nums.size() - 1; i ++) {
            int t = target - nums[i]; // k - a
            for(int j = i + 1, k = nums.size() - 1; j < k;) {
                int m = t - nums[j] - nums[k]; // m = k - a - b - c
                if(abs(m) < diff) {
                    diff = abs(m);
                    ans = target - m;
                }
                if(m > 0) j++;
                else k--;
            }
        }
        return ans;
    }
    int abs(int a) {return a > 0 ? a : -a;}
};
