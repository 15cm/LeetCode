#include <unordered_map>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;
        for(auto& str: strs) {
            string s = strSort(str);
            mp[s].push_back(str);
        }
        for(auto& p: mp) {
            ans.push_back(p.second);
        }
        return ans;
    }
    string strSort(string& s) {
        int cnt[26] = {0};
        for(auto& ch: s) {
            cnt[ch - 'a']++;
        }
        string res(s.length(), 'a');
        int p = 0;
        for(int i = 0; i < 26; i ++)
            for(int j = 0; j < cnt[i]; j ++)
                res[p++] += i;
        return res;
    }
};
