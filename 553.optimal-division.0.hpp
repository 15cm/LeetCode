#define DBL_MAX numeric_limits<double>::max()
#define DBL_MIN numeric_limits<double>::min()
struct Res {
    double minVal, maxVal;
    string minStr, maxStr;
};

class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return "";
        vector<vector<Res>> memo(n, vector<Res>(n));
        for(int i = 0; i < n; i++) {
            auto &r = memo[i][i];
            r.minVal = r.maxVal = nums[i];
            r.minStr = r.maxStr = to_string(nums[i]);
        }
        Res res = dfs(0, n - 1, nums, memo);
        return res.maxStr;
    }
    Res dfs(int lo, int hi, vector<int> &nums, vector<vector<Res>> &memo) {
        if(!memo[lo][hi].minStr.empty()) {
            return memo[lo][hi];
        }
        auto &r = memo[lo][hi];
        r.minVal = DBL_MAX;
        r.maxVal = DBL_MIN;
        for(int i = lo; i < hi; i++) {
            Res left = dfs(lo, i, nums, memo);
            Res right = dfs(i + 1, hi, nums, memo);
            double newMinVal = left.minVal / right.maxVal;
            double newMaxVal = left.maxVal / right.minVal;
            string leftParen = (i + 1 != hi ? "(" : "");
            string rightParen = (i + 1 != hi ? ")" : "");
            if(newMinVal < r.minVal) {
                r.minVal = newMinVal;
                r.minStr = left.minStr + "/" + leftParen + right.maxStr + rightParen;
            }
            if(newMaxVal > r.maxVal) {
                r.maxVal = newMaxVal;
                r.maxStr = left.maxStr + "/" + leftParen + right.minStr + rightParen;
            }
        }
        return memo[lo][hi] = r;
    }
};
