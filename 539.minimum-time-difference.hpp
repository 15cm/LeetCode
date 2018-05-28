class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int> mins(n);
        for(int i = 0; i < n; i++)
            mins[i] = convert(timePoints[i]);
        sort(mins.begin(), mins.end());
        int ans = INT_MAX;
        for(int i = 0; i < n - 1; i++) {
            ans = min(ans, mins[i+1] - mins[i]);
        }
        return min(ans, mins[0] + 24 * 60 - mins[n-1]);
    }
    int convert(const string& s) {
        return stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3));
    }
};
