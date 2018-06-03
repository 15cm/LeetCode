class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int M = 10000;
        int N = 2 * M + 1;
        vector<int> mp(N);
        for(int x: nums) mp[x + M]++;
        int sum = 0;
        for(int offset = 0, i = 0; i < N; i++) {
            int num = i - M;
            sum += (mp[i] + 1 - offset) / 2 * num;
            if(mp[i] % 2) {
                offset = !offset;
            }
        }
        return sum;
    }
};
