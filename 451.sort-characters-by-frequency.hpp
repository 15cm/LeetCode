class Solution {
public:
    string frequencySort(string s) {
        vector<int> cnt(128);
        for(auto c: s) cnt[c]++;
        vector<pair<int, int>> arr;
        for(int i = 0; i < 128; i++) {
            if(cnt[i])
                arr.push_back({cnt[i], i});
        }
        sort(arr.begin(), arr.end(), [](const auto& lhs, const auto& rhs) { return lhs.first > rhs.first; });
        string ans;
        for(auto& pr: arr) {
            ans.append(pr.first, pr.second);
        }
        return ans;
    }
};
