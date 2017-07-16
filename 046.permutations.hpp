#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.empty()) return ans;
        vector<int> seq(nums.size());
        dfs(seq, 0, nums, ans);
        return ans;
    }
    void dfs(vector<int>& seq, int cur, vector<int>& nums, vector<vector<int>>& ans)  {
        if(cur == nums.size()) {
            vector<int> tmp;
            for(auto& index: seq)
                tmp.push_back(nums[index]);
            ans.push_back(tmp);
            return;
        }
        for(int i = 0; i < nums.size(); i ++) {
            bool ok = true;
            for(int j = 0; j < cur; j ++)
                if(i == seq[j]) {
                    ok = false;
                    break;
                }
            if(ok) {
                seq[cur] = i;
                dfs(seq, cur + 1, nums, ans);
            }
        }
    }
};
