typedef vector<int> VI;
typedef vector<VI> VVI;
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        VVI ans;
        VI path;
        VI arr = {1,2,3,4,5,6,7,8,9};

        if(k == 0) return ans;

        backTrack(0, arr, path, n, k, ans);
        return ans;
    }
    void backTrack(int pos, VI& arr, VI& path, int rem, int k, VVI& ans) {
        int n = arr.size();
        if(path.size() == k && rem == 0) {
            ans.push_back(path);
        }
        if(path.size() == k || pos == n || rem < 0) {
            return;
        }

        for(int i = pos; i < n; i++) {
            path.push_back(arr[i]);
            backTrack(i + 1, arr, path, rem - arr[i], k, ans);
            path.pop_back();
        }
    }
};
