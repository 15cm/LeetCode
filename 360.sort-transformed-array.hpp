class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int n = nums.size();
        vector<int> arr = vector<int>(n);
        if(a == 0) {
            int p, step;
            if(b > 0) {
                p = 0;
                step = 1;
            } else {
                p = n-1;
                step = -1;
            }
            for(int i = 0; i < n; i++, p += step) {
                arr[p] = apply(nums[i], a, b, c);
            }
        } else {
            int p, step;
            double x = (double)(-b)/(2*a);
            if(a > 0) {
                p = n-1;
                step = -1;
            } else {
                p = 0;
                step = 1;
            }
            for(int i = 0, j = n-1; i <= j; p += step) {
                double d = abs((double)nums[i] - x) - abs((double)nums[j] - x);
                if(d >= 0) {
                    arr[p] = apply(nums[i++], a, b, c);
                } else {
                    arr[p] = apply(nums[j--], a, b, c);
                }
            }
        }
        return arr;
    }
    int apply(int num, int a, int b, int c) {
        return a*num*num + b*num + c;
    }
};
