class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int x: nums) sum += x;
        if(sum % 2 != 0) return false;
        int V = sum/2;
        vector<bool> f(V+1);
        f[0] = true;
        for(int x: nums) {
            for(int v = V; v >= x; v--) {
                f[v] = f[v] ||  f[v-x];
            }
        }
        return f[V];
    }
};
