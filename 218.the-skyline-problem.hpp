class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        if(buildings.empty()) return vector<pair<int, int>>();
        return getSkyline(buildings, 0, buildings.size() - 1);
    }
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings, int lo, int hi) {
        vector<pair<int, int>> s;
        if(lo == hi) {
            auto& b = buildings[lo];
            s.push_back(make_pair(b[0], b[2]));
            s.push_back(make_pair(b[1], 0));
            return s;
        }
        int mid = lo + (hi - lo) / 2;
        auto s1 = getSkyline(buildings, lo, mid);
        auto s2 = getSkyline(buildings, mid + 1, hi);
        return merge(s1, s2);
    }
    vector<pair<int, int>> merge(vector<pair<int, int>>& s1, vector<pair<int, int>>& s2) {
        vector<pair<int, int>> s;
        int n1 = s1.size(), n2 = s2.size();
        int h1 = 0, h2 = 0, prevH = -1;
        int i = 0, j = 0;
        while(i < n1 && j < n2) {
            int l, l1 = s1[i].first, l2 = s2[j].first;
            if(l1 < l2) {
                h1 = s1[i++].second;
                l = l1;
            } else if (l1 > l2) {
                h2 = s2[j++].second;
                l = l2;
            } else {
                h1 = s1[i++].second;
                h2 = s2[j++].second;
                l = l1;
            }
            int h = max(h1, h2);
            if(h != prevH) {
                s.push_back(make_pair(l, h));
                prevH = h;
            }
        }
        while(i < n1) {
            auto& p = s1[i++];
            int l = p.first, h = p.second;
            if(h != prevH) {
                s.push_back(make_pair(l, h));
                prevH = h;
            }
        }
        while(j < n2) {
            auto& p = s2[j++];
            int l = p.first, h = p.second;
            if(h != prevH) {
                s.push_back(make_pair(l, h));
                prevH = h;
            }
        }
        return s;
    }
};
