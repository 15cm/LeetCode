/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

struct Node {
    Node *left = NULL, *right = NULL;
    int val, lo, hi;
    Node(int lo, int hi): lo(lo), hi(hi), val(0) {}
    Node(int lo, int hi, int val): lo(lo), hi(hi), val(val) {}
};

class Solution {
public:
    // Segment Tree: MLE
    // int minMeetingRooms(vector<Interval>& intervals) {
    //     if(intervals.empty()) return 0;
    //     int left = numeric_limits<int>::max(), right = -1;
    //     for(auto& e: intervals) {
    //         left = min(left, e.start);
    //         right = max(right, e.end);
    //     }
    //     Node* st = buildSegmentTree(left, right);
    //     for(auto& e: intervals)
    //         addInterval(st, e.start + 1, e.end);
    //     int ans = 0;
    //     dfs(st, 0, ans);
    //     return ans;
    // }
    // Node* buildSegmentTree(int start, int end) {
    //     if(start == end) {
    //         return new Node(start, start);
    //     } else {
    //         Node* root = new Node(start, end);
    //         int mid = start + (end - start) / 2;
    //         root->left = buildSegmentTree(start, mid);
    //         root->right = buildSegmentTree(mid + 1, end);
    //         return root;
    //     }
    // }
    // void addInterval(Node* root, int start, int end) {
    //     int lo = root->lo, hi = root->hi;
    //     if(root->lo == start && root->hi == end) {
    //         root->val += 1;
    //         return;
    //     }
    //     int mid = lo + (hi - lo) / 2;
    //     if(end <= mid) addInterval(root->left, start, end);
    //     else if(start > mid) addInterval(root->right, start, end);
    //     else {
    //         addInterval(root->left, start, mid);
    //         addInterval(root->right, mid + 1, end);
    //     }
    // }
    // void dfs(Node* root, int sum, int& ans) {
    //     if(!root) {
    //         ans = max(sum, ans);
    //         return;
    //     }
    //     dfs(root->left, root->val + sum, ans);
    //     dfs(root->right, root->val + sum, ans);
    // }
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](Interval& lhs, Interval& rhs) {
                return lhs.start < rhs.start;
            });
        auto cmp = [](Interval& lhs, Interval& rhs) {
            return lhs.end > rhs.end;
        };
        priority_queue<Interval, vector<Interval>, decltype(cmp)> pq(cmp);
        int ans = 0;
        for(auto& item: intervals) {
            while(!pq.empty() && pq.top().end <= item.start)
                pq.pop();
            pq.push(item);
            ans = max(ans, (int)pq.size());
        }
        return ans;
    }
};
