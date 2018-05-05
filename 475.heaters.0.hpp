class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        auto b = heaters.begin(), e = heaters.end();
        int ans = 0;
        for(int x: houses) {
            if(x <= *b) ans = max(ans, *b - x);
            else if(x >= *(e-1)) ans = max(ans, x - *(e-1));
            else {
                auto it = upper_bound(b, e, x);
                ans = max(ans, min(*it - x, x - *(it-1)));
            }
        }
        return ans;
    }
};
