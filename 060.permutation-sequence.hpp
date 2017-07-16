#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string getPermutation(int n, int k) {
        int sz = factorial(n);
        if(k > sz) return "";
        k -= 1;
        string ans(n, '0');
        vector<int> nums;
        for(int i = 1; i <= n; i ++) nums.push_back(i);
        for(int i = 0; i < n; i ++) {
            sz /= (n - i);
            int grpNum = k / sz ;
            ans[i] = nums[grpNum] + '0';
            nums.erase(nums.begin() + grpNum);
            k %= sz;
        }
        return ans;
    }
    int factorial(int n) {
        if(n == 0) return 1;
        int ans = n;
        while(--n > 1) {
            ans *= n;
        }
        return ans;
    }
};
