class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int sz = m + n;
        auto it1 = nums1.begin(), it2 = nums2.begin();
        if(sz % 2) {
            return findKth(it1, m, it2, n, sz / 2 + 1);
        } else {
            return (findKth(it1, m, it2, n, sz / 2) + findKth(it1, m, it2, n, sz / 2 + 1)) * 1.0 / 2;
        }
    }
    int findKth(vector<int>::iterator it1, int m, vector<int>::iterator it2, int n, int k) {
        if(k > m + n || k < 1) return -1;
        if(m > n) return findKth(it2, n, it1, m, k);
        if(m == 0) return *(it2 + k - 1);
        if(k == 1) return min(*it1, *it2);
        int i = min(m, k / 2), j = min(n, k / 2);
        if(*(it1 + i - 1) < *(it2 + j - 1)) {
            return findKth(it1 + i, m - i, it2, n, k - i);
        } else {
            return findKth(it1, m, it2 + j, n - j, k - j);
        }
    }
};
