class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        if(buildings.empty()) return {};
        return mergeSort(buildings, 0, buildings.size() - 1);
    }
    vector<pair<int, int>> mergeSort(vector<vector<int>> &rects, int lo, int hi) {
        if(lo == hi) return {{rects[lo][0], rects[lo][2]}, {rects[lo][1], 0}};
        int mid = lo + (hi - lo) / 2;
        auto left = mergeSort(rects, lo, mid);
        auto right = mergeSort(rects, mid + 1, hi);
        return merge(left, right);
    }
    vector<pair<int, int>> merge(vector<pair<int, int>> &l, vector<pair<int, int>> &r) {
        int m = l.size(), n = r.size();
        vector<pair<int, int>> res;
        int prev_h = 0;
        for(int i = 0, j = 0, hl = 0, hr = 0; i < m || j < n;) {
            int k;
            if(i < m && j < n && l[i].first == r[j].first) {
                hl = l[i].second;
                hr = r[j].second;
                k = l[i].first;
                i++;
                j++;
            } else if(j == n || i < m && l[i].first < r[j].first) {
                hl = l[i].second;
                k = l[i].first;
                i++;
            } else {
                hr = r[j].second;
                k = r[j].first;
                j++;
            }
            int h = max(hl, hr);
            if(h != prev_h) {
                res.emplace_back(k, h);
                prev_h = h;
            }
        }
        return res;
    }
};
