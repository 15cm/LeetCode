#include <vector>
using namespace std;
class Solution {
public:
    // DFS, TLE
    int combinationSum4(vector<int>& nums, int target) {
        int ans = 0;
        vector<int> stat(nums.size());
        dfs(0, nums, stat, target, ans);
        return ans;
    }
    void dfs(int cur, vector<int>& nums, vector<int>& stat, int target, int& ans) {
        if(target == 0) {
            ans += multinomial(stat);
            return;
        }
        if(cur == nums.size()) return;
        dfs(cur + 1, nums, stat, target, ans);
        int cnt = 0;
        while((target -= nums[cur]) >= 0) {
            stat[cur] = ++cnt;
            dfs(cur + 1, nums, stat, target, ans);
        }
        stat[cur] = 0;
    }
    int binomial(int n, int k) {
        vector<int> f(k+1);
        f[0] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = min(i, k); j > 0; j--) {
                f[j] = f[j] + f[j-1];
            }
        }
        return f[k];
    }
    int multinomial(vector<int>& nums) {
        int product = 1, sum = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > 0) {
                sum += nums[i];
                product *= binomial(sum, nums[i]);
            }
        }
        return product;
    }
};
