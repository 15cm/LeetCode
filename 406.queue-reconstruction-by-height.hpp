class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(), [](const auto& p1, const auto& p2) {
                return p1.first > p2.first || p1.first == p2.first && p1.second < p2.second;
            });
        vector<pair<int, int>> ans;
        for(const auto& p: people) {
            ans.insert(ans.begin() + p.second, p);
        }
        return ans;
    }
};
