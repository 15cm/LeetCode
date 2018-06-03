class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> st;
        int cnt = 0;
        for(auto x: candies) {
            if(!st.count(x)) {
                cnt++;
                st.insert(x);
            }
        }
        return min(cnt, (int)candies.size() / 2);
    }
};
