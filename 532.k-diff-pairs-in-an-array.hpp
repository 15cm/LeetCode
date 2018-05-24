class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k < 0) return 0;
        int ans = 0;
        if(k == 0) {
            unordered_map<int, int> mp;
            for(int x: nums) mp[x]++;
            for(auto& pr: mp) {
                if(pr.second > 1)
                    ans++;
            }
        } else {
            unordered_set<int> st;
            for(int x: nums) st.insert(x);
            for(auto it = st.begin(); it != st.end(); it = st.erase(it)) {
                if(st.count(*it - k)) ans++;
                if(st.count(*it + k)) ans++;
            }
        }
        return ans;
    }
};
