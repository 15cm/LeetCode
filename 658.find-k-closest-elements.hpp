class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int> ans(k);
        auto it = lower_bound(arr.begin(), arr.end(), x);
        int i, j;
        if(it == arr.begin()) {
            i = 0, j = 1;
        } else {
            i = it - arr.begin() - 1;
            j = i + 1;
        }
        for(int p = 0; p < k; p++) {
            if(i < 0 || j < n && abs(arr[i] - x) > abs(arr[j] - x)) {
                ans[p] = arr[j++];
            } else {
                ans[p] = arr[i--];
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
