#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = nums.size();
        // record f[0/1][i] -> f[0][i-1] / f[1][i-1]
        vector<vector<int>> path(2, vector<int>(n));
        int f0 = 0, f1 = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            int t = f0;
            if(f1 > f0) {
                path[0][i] = 1;
            } else {
                path[0][i] = 0;
            }
            f0 = max(f0, f1);
            f1 = t + nums[i];
            path[1][i] = 0;
        }
        vector<int> res;
        int i, j;
        if(f1 > f0) {
            res.push_back(n - 1);
            i = 0, j = n - 2;
        } else {
            i = 0, j = n - 1;
        }
        while(j > 0) {
            if(path[i][j] == 1) {
                res.push_back(j - 1);
            }
            i = path[i][j];
            j--;
        }
        for(auto e: res) {
            cout << e << " ";
        }
        cout << endl;
        return max(f0, f1);
    }
};
