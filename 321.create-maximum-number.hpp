class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        vector<int> ans(k);
        for(int i = max(0, k-m); i <= k && i <= n; i++) {
            auto cand = merge(maxSubSeq(nums1, i), maxSubSeq(nums2, k - i));
            if(gt(cand, 0, ans, 0)) ans = cand;
        }
        return ans;
    }
    vector<int> merge(const vector<int>& lhs, const vector<int>& rhs) {
        int n = lhs.size(), m = rhs.size();
        vector<int> res(n+m);
        for(int i = 0, j = 0, k = 0; i < n || j < m; k++) {
            if(i == n) res[k] = rhs[j++];
            else if(j == m) res[k] = lhs[i++];
            else if(gt(lhs, i, rhs, j)) res[k] = lhs[i++];
            else res[k] = rhs[j++];
        }
        return res;
    }
    bool gt(const vector<int>& lhs, int i, const vector<int>& rhs, int j) {
        int n = lhs.size(), m = rhs.size();
        while(i < n && j < m && lhs[i] == rhs[j]) {
            i++;
            j++;
        }
        return j == m || i < n && lhs[i] > rhs[j];
    }
    vector<int> maxSubSeq(vector<int>& vec, int len) {
        int n = vec.size();
        vector<int> res(len);
        for(int i = 0, j = 0; i < n; i++) {
            while(n - i + j > len && j > 0 && res[j-1] < vec[i]) j--;
            if(j < len) res[j++] = vec[i];
        }
        return res;
    }
};
