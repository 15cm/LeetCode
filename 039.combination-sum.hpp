#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        vector<int> state(candidates.size());
        state.assign(candidates.size(), 0);
        search(candidates, target, state, 0, ans);
        return ans;
    }

    void search(const vector<int>& candidates, int target, vector<int> state, int cur, vector<vector<int>>& ans) {
        if(target == 0) {
            vector<int> tmp;
            for(int i = 0; i < state.size(); i ++) {
                for(int j = 0; j < state[i]; j ++) {
                    tmp.push_back(candidates[i]);
                }
            }
            ans.push_back(tmp);
            return;
        }
        if(cur >= candidates.size() || target < 0) return;
        for(int i = target / candidates[cur]; i >= 0; i --) {
            state[cur] = i;
            search(candidates, target - i * candidates[cur], state, cur + 1, ans);
        }
    }
};
