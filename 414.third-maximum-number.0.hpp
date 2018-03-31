class Solution {
public:
    int thirdMax(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_set<int> st;
        for(int x: nums) {
            if(st.count(x)) continue;
            st.insert(x);
            if(pq.size() < 3) {
                pq.push(x);
            } else if(x > pq.top()) {
                pq.pop();
                pq.push(x);
            }
        }
        int ans;
        if(pq.size() < 3) {
            while(!pq.empty()) {
                ans = pq.top(); pq.pop();
            }
        } else {
            ans = pq.top();
        }
        return ans;
    }
};
