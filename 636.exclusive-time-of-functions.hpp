class Solution {
    struct Log {
        int id;
        bool isStart;
        int val;
        Log(int id, bool isStart, int val): id(id), isStart(isStart), val(val) {}
    };
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n);
        stack<int> stk;
        Log log = parseLog(logs[0]);
        stk.push(log.id);
        int prev = log.val;
        for(int i = 1; i < logs.size(); i++) {
            Log log = parseLog(logs[i]);
            if(log.isStart) {
                if(!stk.empty()) {
                    ans[stk.top()] += log.val - prev;
                }
                prev = log.val;
                stk.push(log.id);
            } else {
                ans[stk.top()] += log.val - prev + 1;
                prev = log.val + 1;
                stk.pop();
            }
        }

        return ans;
    }
    Log parseLog(string s) {
        int part1 = s.find_first_of(":");
        int part2 = s.find_last_of(":");
        int id = stoi(s.substr(0, part1));
        bool isStart = s.substr(part1 + 1, part2 - part1 - 1) == "start";
        int val = stoi(s.substr(part2 + 1));
        return Log(id, isStart, val);
    }
};
