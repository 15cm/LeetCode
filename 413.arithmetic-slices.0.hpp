class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        int f = 0;
        int sum = 0;
        for(int i = 2; i < n; i++) {
            if(A[i] - A[i-1] == A[i-1] - A[i-2]) {
                f = 1 + f;
                sum += f;
            } else {
                f = 0;
            }
        }
        return sum;
    }
};
