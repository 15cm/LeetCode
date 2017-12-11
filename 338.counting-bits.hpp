class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> f(num+1);
        for(int i = 1; i <= num; i++) {
            int mask = i & (-i);
            f[i] = f[i ^ mask] + 1;
        }
        return f;
    }
};
