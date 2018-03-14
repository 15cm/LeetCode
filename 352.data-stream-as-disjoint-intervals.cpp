/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
    vector<Interval> intvs;

public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        if(intvs.empty()) {
            intvs.push_back(Interval(val, val));
            return;
        }
        auto b = intvs.begin(), e = intvs.end();
        auto it = upper_bound(b, e, val, [](const auto& val, const auto& ele) {
                return val < ele.start;
            });

        bool merged = false;

        if(it != b) {
            auto pit = prev(it);
            if(val - pit->end <= 1) {
                pit->end = max(val, pit->end);
                merged = true;
            }
        }

        if(it != e) {
            if(it->start - val == 1) {
                it->start = val;
                merged = true;
            }
        }

        if(merged) {
            if(it != b && it != e) {
                auto pit = prev(it);
                if(it->start - pit->end <= 1) {
                    pit->end = it->end;
                    intvs.erase(it);
                }
            }
        } else {
            intvs.insert(it, Interval(val, val));
        }
    }

    vector<Interval> getIntervals() {
        return intvs;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */
