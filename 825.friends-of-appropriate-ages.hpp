class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(), ages.end());
        int ans = 0;
        for(auto it = ages.begin(); it != ages.end(); it++) {
            auto it_left1 = lower_bound(ages.begin(), ages.end(), *it);
            auto it_left2 = (*it > 100 ? lower_bound(ages.begin(), ages.end(), 100) : ages.begin());
            auto it_right = lower_bound(ages.begin(), ages.end(), 2 * (*it - 7));
            int len = min(it_right - it_left1, it_right - it_left2);
            if(len > 0) {
                ans += len;
                if((it >= it_left1 || it >= it_left2) && it < it_right)
                    ans--;
            }
        }
        return ans;
    }
};
