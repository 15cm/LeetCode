class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<pair<int, int>> stk;
        int id, val;
        bool is_start;
        vector<int> ans(n);
        for(auto &log: logs) {
            parse_log(log, id, is_start, val);
            if(is_start) {
                if(!stk.empty()) {
                    auto &prev = stk.top();
                    ans[prev.first] += val - prev.second;
                }
                stk.emplace(id, val);
            } else {
                ans[id] += val - stk.top().second + 1;
                stk.pop();
                if(!stk.empty()) {
                    stk.top().second = val + 1;
                }
            }
        }
        return ans;
    }
    void parse_log(string &s, int &id, bool &is_start, int &val) {
        int p1 = s.find(':'), p2 = s.find(':', p1 + 1);
        id = stoi(s.substr(0, p1));
        is_start = (s.substr(p1 + 1, p2 - p1 - 1) == "start");
        val = stoi(s.substr(p2 + 1));
    }
};
