#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int d[n];
        bool visit[n];
        for(int i = 0; i < n; i ++) {
            d[i] = (i == 0 ? 0 : n);
            visit[i] = false;
        }
        int u = 0;
        for(int i = 0; i < n - 1; i ++) {
            if(i > 0 && i + nums[i] <= u + nums[u]) continue;
            for(int j = 0; j <= nums[i]; j ++) {
                int w = i + j;
                if(w < n) {
                    if(d[i] + 1 < d[w]) d[w] = d[i] + 1; 
                }
            }
            u = i;
        }
        return d[n-1];
    }
};
