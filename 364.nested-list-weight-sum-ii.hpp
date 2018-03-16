/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int depth = 0;
        vector<int> levelSum;
        queue<const NestedInteger*> q;
        for(auto& num: nestedList) {
            q.push(&num);
        }

        while(!q.empty()) {
            int sz = q.size();
            int sum = 0;
            while(sz--) {
                auto x = q.front();
                q.pop();
                if(x->isInteger()) {
                    sum += x->getInteger();
                } else {
                    for(auto& num: x->getList()) {
                        q.push(&num);
                    }
                }
            }
            levelSum.push_back(sum);
            depth++;
        }

        int ans = 0;
        for(int x: levelSum) {
            ans += x * (depth--);
        }
        return ans;
    }
};
