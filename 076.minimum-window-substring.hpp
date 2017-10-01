#define INF numeric_limits<int>::max()
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> mp(128, 0);
        int head = 0, begin = 0, end = 0, d = INF, counter = t.size();
        for(char c: t) mp[c]++;
        while(end < s.size()) {
            if(mp[s[end++]]-- > 0) counter--;
            while(counter == 0) {
                if(end - begin < d) d = end - (head = begin);
                if(mp[s[begin++]]++ == 0) counter++;
            }
        }
        return d == INF ? "" : s.substr(head, d);
    }
};
