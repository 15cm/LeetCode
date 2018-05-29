
class Solution {
public:
    bool splitArray(vector<int>& nums) {
        int n = nums.size();
        if(n < 7) return false;
        vector<int> sum(n);
        for(int i = 0; i < n; i++) {
            sum[i] = (i > 0 ? sum[i - 1] : 0) + nums[i];
        }

        for(int j = 3; j < n - 3; j++) {
            unordered_set<int> st;
            for(int i = 1; i < j - 1; i++) {
                if(sum[i - 1] == sum[j - 1] - sum[i]) {
                    st.insert(sum[i - 1]);
                }
            }

            for(int k = j + 2; k < n - 1; k++) {
                if(st.count(sum[k - 1] - sum[j]) && sum[k - 1] - sum[j] == sum[n - 1] - sum[k]) {
                    return true;
                }
            }
        }
        return false;
    }
};
