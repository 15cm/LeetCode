#include <iostream>
#include <list>
using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        int n = path.length();
        list<string> p;
        p.push_back("/");
        if(path.empty() || path[0] != '/') return "/";
        for(int i = 0; i < n;) {
            int j = i + 1;
            while(j < n && path[j] == '/') j++;
            if(j == n) break;
            i = j;
            while(j < n && path[j] != '/') j++;
            string relPath = path.substr(i, j - i);
            if(relPath == ".");
            else if(relPath == "..") {
                if(p.back() != "/") p.erase(prev(p.end()));
            } else {
                p.push_back(relPath);
            }
            i = j;
        }
        string ans = "/";
        auto it = next(p.begin());
        if(it == p.end()) return ans;
        while(it != p.end()) {
            ans += *it + '/';
            it++;
        }
        return ans.substr(0, ans.length() - 1);
    }
};
