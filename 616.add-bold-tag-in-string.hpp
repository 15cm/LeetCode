class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        vector<pair<int, int>> itvs;
        for(auto& t: dict) {
            if(t.empty()) continue;
            int start = s.find(t);
            while(start != -1) {
                itvs.push_back(make_pair(start, start + t.length()));
                start = s.find(t, start + 1);
            }
        }
        sort(itvs.begin(), itvs.end());
        if(itvs.empty()) return s;
        int i = 0;
        for(int j = 1; j < itvs.size(); j++) {
            if(itvs[j].first > itvs[i].second) {
                itvs[++i] = itvs[j];
            } else {
                itvs[i].first = min(itvs[i].first, itvs[j].first);
                itvs[i].second = max(itvs[i].second, itvs[j].second);
            }
        }
        string ans;
        int j = 0;
        for(int k = 0; k <= s.length(); k++) {
            if(j <= i && k == itvs[j].first) {
                    ans += "<b>";
            }
            ans.push_back(s[k]);
            if(j <= i && k + 1 == itvs[j].second) {
                ans += "</b>";
                j++;
            }
        }
        return ans;
    }
};
