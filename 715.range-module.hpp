class RangeModule {
public:
    vector<pair<int, int>> itvs;
    RangeModule() {
    }
    
    void addRange(int left, int right) {
        auto it = itvs.begin();
        vector<pair<int, int>> tmp;
        for(;it != itvs.end() && it->second < left; it++)
            tmp.push_back(*it);
        auto itv = make_pair(left, right);
        for(; it != itvs.end() && it->first <= right; it++) {
            itv.first = min(itv.first, it->first);
            itv.second = max(itv.second, it->second);
        }
        tmp.push_back(itv);
        for(; it != itvs.end(); it++)
            tmp.push_back(*it);
        swap(itvs, tmp);
    }
    
    bool queryRange(int left, int right) {
        int n = itvs.size();
        int lo = 0, hi = n - 1;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if(itvs[mid].first >= right) {
                hi = mid - 1;
            } else if(itvs[mid].second <= left) {
                lo = mid + 1;
            } else {
                return itvs[mid].first <= left && itvs[mid].second >= right;
            }
        }
        return false;
    }
    
    void removeRange(int left, int right) {
        vector<pair<int, int>> tmp;
        for(auto& itv: itvs) {
            if(itv.second <= left || itv.first >= right)
                tmp.push_back(itv);
            else {
                if(itv.first < left) tmp.push_back(make_pair(itv.first, left));
                if(itv.second > right) tmp.push_back(make_pair(right, itv.second));
            }
        }
        swap(itvs, tmp);
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule obj = new RangeModule();
 * obj.addRange(left,right);
 * bool param_2 = obj.queryRange(left,right);
 * obj.removeRange(left,right);
 */
