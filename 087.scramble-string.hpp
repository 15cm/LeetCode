#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool isScramble(string s1, string s2) {
        unordered_map<string, bool> cache;
        return dfs(cache, s1, s2);
    }
    bool dfs(unordered_map<string, bool>& cache, string s1, string s2) {
        if(s1 == s2) return true;
        string shash = s1 + s2;
        if(cache.find(shash) != cache.end()) return cache[shash];
        if(!sameCharSet(s1, s2)) return false;
        int n = s1.length();
        bool res = false;
        for(int len = 1; len < n; len ++) {
            if(res = ((dfs(cache, s1.substr(0, len), s2.substr(0, len)) && dfs(cache, s1.substr(len), s2.substr(len)))
                      || (dfs(cache, s1.substr(0, n - len), s2.substr(len)) && dfs(cache, s1.substr(n - len), s2.substr(0, len)))))
                break;
        }
        return cache[s1+s2] = res;
    }
    bool sameCharSet(string& s1, string& s2) {
        if(s1.length() != s2.length()) return false;
        int cnt[128] = {0};
        for(int i = 0; i < s1.length(); i ++) {
            cnt[s1[i]]++; cnt[s2[i]]--;
        }
        for(int i = 0; i < 128; i ++)
            if(cnt[i] != 0) return false;
        return true;
    }
};
