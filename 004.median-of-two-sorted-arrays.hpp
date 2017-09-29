class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size(), n = n1 + n2;
        auto it1 = nums1.begin(), it2 = nums2.begin();
        if(n & 1) return kthSmallest(it1, n1, it2, n2, (n+1)/2);
        else return (kthSmallest(it1, n1, it2, n2, n/2) + kthSmallest(it1, n1, it2, n2, n/2 + 1)) * 1.0 / 2;
    }
    int kthSmallest(vector<int>::iterator it1, int n1, vector<int>::iterator it2, int n2, int k) {
        if(n1 > n2) return kthSmallest(it2, n2, it1, n1, k);
        if(n1 == 0) return *(it2 + k - 1);
        if(k == 1) return min(*it1, *it2);
        int m1 = min(n1, k/2), m2 = min(n2, k/2);
        if(*(it1 + m1 - 1) < *(it2 + m2 - 1)) {
            return kthSmallest(it1 + m1, n1 - m1, it2, n2, k - m1);
        } else {
            return kthSmallest(it1, n1, it2 + m2, n2 - m2, k - m2);
        }
    }
};
