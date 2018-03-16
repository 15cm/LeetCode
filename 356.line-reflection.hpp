using intpair = pair<int, int>;
class Solution {
    struct intpair_hash {
        size_t operator() (const intpair& x) const {
            return (((size_t) x.first) << 32) | x.second;
        }
    };
public:
    bool isReflected(vector<pair<int, int>>& points) {
        if(points.empty()) return true;
        int left = INT_MAX, right = INT_MIN;

        unordered_set<intpair, intpair_hash> st;

        for(auto& p: points) {
            left = min(p.first, left);
            right = max(p.first, right);

            st.insert(p);
        }

        for(auto& p: points) {
            int x = left + right - p.first;
            int y = p.second;
            if(!st.count({x, y}))
                return false;
        }
        return true;
    }
};
