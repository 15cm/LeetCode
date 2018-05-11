class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        unordered_map<int, int> mp;
        stack<int> stk;
        for(int x: nums) {
            while(!stk.empty() && x > stk.top()) {
                int prev = stk.top(); stk.pop();
                mp[prev] = x;
            }
            stk.push(x);
        }
        for(int &x: findNums) {
            x = mp.count(x) ? mp[x] : -1;
        }
        return findNums;
    }
};
