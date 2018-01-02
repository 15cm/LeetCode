#include <vector>
using namespace std;
class Solution {
    vector<bool> vcol, vmain, vanti;
public:
    int totalNQueens(int n) {
        vcol = vector<bool>(n);
        vmain = vanti = vector<bool>(2*n - 1);
        int ans = 0;
        dfs(0, n, ans);
        return ans;
    }
    void dfs(int row, int n, int& ans) {
        if(row == n) {
            ans++;
            return;
        }
        for(int i = 0; i < n; i++) {
            int imain = i - row + n - 1, ianti = i + row;
            if(!(vcol[i] || vmain[imain] || vanti[ianti])) {
                vcol[i] = vmain[imain] = vanti[ianti] = true;
                dfs(row+1, n, ans);
                vcol[i] = vmain[imain] = vanti[ianti] = false;
            }
        }
    }
};
