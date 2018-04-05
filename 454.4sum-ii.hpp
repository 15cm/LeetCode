class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> mp;
        int n = A.size();
        int ans = 0;
        for(int a: A)
            for(int b: B)
                mp[a+b]++;
        for(int c: C)
            for(int d: D) {
                int x = -(c+d);
                ans += mp.count(x) ? mp[x] : 0;
            }
        return ans;
    }
};
