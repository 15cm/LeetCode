class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> arr(nums.begin(), nums.end());
        return dfs(arr);
    }
    bool dfs(vector<double>& arr) {
        int n = arr.size();
        if(n == 0) return false;
        if(n == 1) return abs(arr[0] - 24) < 1e-6;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                vector<double> nextLevel;
                for(int k = 0; k < n; k++)
                    if(k != i && k != j)
                        nextLevel.push_back(arr[k]);
                double a = arr[i], b = arr[j];
                for(int k = 0; k < 4; k++) {
                    if(k < 2 && j < i) continue;
                    if(k == 0) nextLevel.push_back(a + b);
                    else if(k == 1) nextLevel.push_back(a * b);
                    else if(k == 2) nextLevel.push_back(a - b);
                    else {
                        if(b != 0)
                            nextLevel.push_back(a / b);
                        else
                            continue;
                    }
                    if(dfs(nextLevel))
                        return true;
                    nextLevel.pop_back();
                }
            }
        return false;
    }
};
