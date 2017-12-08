class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<bool> path(10);
        vector<string> ans;
        dfs(0, num, path, ans);
        return ans;
    }
    void dfs(int p, int k, vector<bool>& path, vector<string>& ans) {
        int n = path.size();
        if(!isValid(path)) return;
        if(k == 0 || p == n) {
            if(k == 0) {
                ans.push_back(toTime(path));
            }
            return;
        }
        for(int i = p; i < n; i++) {
            path[i] = true;
            dfs(i+1, k-1, path, ans);
            path[i] = false;
        }
    }

    int getHour(const vector<bool>& vec) {
        int sum = 0;
        for(int i = 0; i < 4; i++) {
            sum <<= 1;
            sum += vec[i];
        }
        return sum;
    }

    int getMinute(const vector<bool>& vec) {
        int sum = 0;
        for(int i = 4; i < vec.size(); i++) {
            sum <<= 1;
            sum += vec[i];
        }
        return sum;
    }

    bool isValid(const vector<bool>& vec) {
        return getHour(vec) < 12 && getMinute(vec) < 60;
    }
    string toTime(const vector<bool>& vec) {
        int h = getHour(vec), m = getMinute(vec);
        return to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m);
    }
};
