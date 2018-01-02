class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for(int x: nums) {
            if(st.count(x)) return true;
            else st.insert(x);
        }
        return false;
    }
};
