class Solution {
public:
    string findContestMatch(int n) {
        vector<string> nums(n);
        for(int i = 1; i <= n; i++)
            nums[i - 1] = to_string(i);
        int sz = n;
        for(int sz = n; sz > 1; sz >>= 1) {
            for(int i = 0; i < sz / 2; i++) {
                nums[i] = formPair(nums[i], nums[sz - 1 - i]);
            }
        }
        return nums[0];
    }
    string formPair(const string& lhs, const string &rhs) {
        return "(" + lhs + "," + rhs + ")";
    }
};
