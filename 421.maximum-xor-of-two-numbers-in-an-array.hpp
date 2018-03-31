class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        unordered_set<int> st;
        int mask = 0;
        int ans = 0;
        for(int i = 30; i >= 0; i--) {
            mask = mask | (1 << i);
            st.clear();
            for(int x: nums) {
                st.insert(x & mask);
            }
            int candidate = ans | (1 << i);
            for(auto prefix: st) {
                if(st.count(candidate ^ prefix)) {
                    ans = candidate;
                    break;
                }
            }
        }
        return ans;
    }
};
