#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> seq(k);
        vector<vector<int>> ans;
        if(n < 1 || k < 1) return ans;
        for(int num = 1; num <= n; num++) {
            seq[0] = num;
            dfs(seq, 1, n, k, ans);
        }
        return ans;
    }
    void dfs(vector<int>& seq, int cur, int n, int k, vector<vector<int>>& ans) {
        if(cur == k) {
            ans.push_back(seq);
            return;
        }
        for(int num = seq[cur - 1] + 1; num <= n; num++) {
            seq[cur] = num;
            dfs(seq, cur + 1, n, k, ans);
        }
    }
};
