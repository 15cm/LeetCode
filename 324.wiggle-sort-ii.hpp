class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        auto midPtr = nums.begin() + n/2;
        nth_element(nums.begin(), midPtr, nums.end());
        int mid = *midPtr;

#define A(i) nums[getIdx(i, n)]
        for(int i = 0, j = n - 1, k = 0; k <= j;) {
            if(A(k) > mid) {
                swap(A(i++), A(k++));
            } else if(A(k) < mid) {
                swap(A(k), A(j--));
            } else {
                k++;
            }
        }
    }
    int getIdx(int i, int n) {
        return i < n/2 ? 2*i + 1 : 2*(i - n/2);
    }
};
