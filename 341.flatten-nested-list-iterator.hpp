/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

typedef NestedInteger NI;
typedef vector<NI> VNI;
typedef VNI::iterator VNIIT;

class NestedIterator {
    stack<pair<VNIIT, VNIIT>> s;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        if(!nestedList.empty()) s.push(make_pair(nestedList.begin(), nestedList.end()));
    }

    int next() {
        hasNext();
        // inner finished and forwarded
        return (s.top().first++)->getInteger();
    }

    bool hasNext() {
        while(!s.empty()) {
            auto x = s.top();
            if(x.first == x.second) {
                s.pop();
            } else {
                auto cur = x.first;
                if(cur->isInteger()) return true;
                // outer finished and forwarded
                s.top().first++;
                s.push(make_pair(cur->getList().begin(), cur->getList().end()));
            }
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
