#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        int maxIndex = 0;
        for(; maxIndex < candidates.size() && candidates[maxIndex] <= target; maxIndex ++);
        if(maxIndex == 0)  return ans;
        candidates.resize(maxIndex);
        vector<int> capacities = uniqueAndReturnCount(candidates);
        vector<int> state(candidates.size());
        search(candidates, target, capacities, state, 0, ans);
        return ans;
    }

    vector<int> uniqueAndReturnCount(vector<int>& vec) {
        int i = 0, j = 0;
        vector<int> cnt(vec.size(), 1);
        while(true) {
            while(j < vec.size() - 1 && vec[j] == vec[j+1]) {
                j++;
                cnt[i]++;
            }
            vec[i] = vec[j];
            i++;
            if(j == vec.size() - 1) break;
            else j++;
        }
        vec.resize(i);
        cnt.resize(i);
        return cnt;
    }


    void search(const vector<int>& candidates, int target, const vector<int>& capacities, vector<int> state, int cur, vector<vector<int>>& ans) {
        if(target == 0) {
            vector<int> tmp;
            for(int i = 0; i < state.size(); i ++)
                for(int j = 0; j < state[i]; j ++) {
                    tmp.push_back(candidates[i]);
                }
            ans.push_back(tmp);
            return;
        }
        if(cur >= candidates.size() || target < 0) return;
        for(int i = min(capacities[cur], target / candidates[cur]); i >= 0; i --) {
            state[cur] = i;
            search(candidates, target - i * candidates[cur], capacities, state, cur + 1, ans);
        }
    }
};
