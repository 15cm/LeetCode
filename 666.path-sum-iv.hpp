class Solution {
    const int sz = 32;
    vector<int> tree = vector<int>(sz, -1);
public:
    int pathSum(vector<int>& nums) {
        if(nums.empty()) return 0;
        for(int num: nums) {
            int d = num / 100;
            int c = num % 100 / 10;
            int v = num % 10;
            tree[(1 << (d - 1)) + c - 1] = v;
        }
        int sum = 0;
        dfs(1, 0, sum);
        return sum;
    }
    void dfs(int p, int path, int &sum) {
        path += tree[p];
        int left = p * 2, right = p * 2 + 1;
        if(!exists(left) && !exists(right)) {
            sum += path;
        } else {
            if(exists(left)) {
                dfs(left, path, sum);
            }
            if(exists(right)) {
                dfs(right, path, sum);
            }
        }
    }
    bool exists(int p) {
        return p < sz && tree[p] != -1;
    }
};
