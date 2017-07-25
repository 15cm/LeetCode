#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<vector<int>> ans;
        vector<int> lens(3);
        dfs(lens, 0, 0, ans, s);
        vector<string> ips;
        for(auto& points: ans) {
            string tmp;
            int cur = 0;
            for(auto& point: points) {
                tmp += s.substr(cur, point) + ".";
                cur += point;
            }
            tmp += s.substr(cur);
            ips.push_back(tmp);
        }
        return ips;
    }
    void dfs(vector<int>& lens, int n, int cur, vector<vector<int>>& ans, string& s) {
        if(n == 3) {
            if(cur != s.length() && validIp(s.substr(cur)))
                ans.push_back(lens);
        } else {
            for(int i = 1; cur + i < s.length() && i <= 3; i++) {
                if(validIp(s.substr(cur, i))) {
                    lens[n] = i;
                    dfs(lens, n + 1, cur + i, ans, s);
                }
            }
        }
    }
    bool validIp(string s) {
        if(!(s.length() >= 1 && s.length() <= 3)) return false;
        if(s.length() > 1 && s[0] == '0') return false;
        int ip = stoi(s);
        return ip >= 0 && ip <= 255;
    }
};
