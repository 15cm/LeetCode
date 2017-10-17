class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        vector<vector<int>> ans;
        if(candidates.empty()) return ans;
        backTrack(0, candidates, path, target, ans);
        return ans;
    }

    void backTrack(int pos, vector<int>& arr, vector<int>& path, int rem, vector<vector<int>>& ans) {
        if(rem < 0) return;
        if(rem == 0) {
            ans.push_back(path);
            return;
        }

        for(int i = pos; i < arr.size(); i++) {
            path.push_back(arr[i]);
            backTrack(i, arr, path, rem - arr[i], ans);
            path.pop_back();
        }
    }
};
