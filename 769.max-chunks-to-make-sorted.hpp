class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> stk;
        for(int v: arr) {
            if(stk.empty() || v > stk.top()) {
                stk.push(v);
            } else {
                int tmp = stk.top();
                while(!stk.empty() && v < stk.top()) stk.pop();
                stk.push(tmp);
            }
        }
        return stk.size();
    }
};
