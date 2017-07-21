#include <vector>
#include <algorithm>
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = m - 1; i >= 0; i--)
            nums1[i + n] = nums1[i];
        for(int p = 0, i = n, j = 0; i < m + n || j < n;) {
            if(i == m + n) {
                nums1[p++] = nums2[j++];
            } else if(j == n) {
                nums1[p++] = nums2[i++];
            } else {
                if(nums1[i] < nums2[j]) nums1[p++] = nums1[i++];
                else nums1[p++] = nums2[j++];
            }
        }
    }
};
