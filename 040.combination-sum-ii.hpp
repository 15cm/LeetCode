class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        if(candidates.empty()) return ans;
        vector<int> path;

        sort(candidates.begin(), candidates.end());
        backTrack(0, candidates, path, target, ans);
        return ans;
    }
    void backTrack(int pos, vector<int>& arr, vector<int>& path, int rem, vector<vector<int>>& ans) {
        if(rem == 0) {
            ans.push_back(path);
            return;
        }
        if(pos == arr.size() || rem < 0) return;

        for(int i = pos; i < arr.size(); i++) {
            if(i > pos && arr[i] == arr[i-1])
                continue;
            path.push_back(arr[i]);
            backTrack(i + 1, arr, path, rem - arr[i], ans);
            path.pop_back();
        }
    }
};
