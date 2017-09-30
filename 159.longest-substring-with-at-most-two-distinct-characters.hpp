class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        vector<int> mp(128, 0);
        int begin = 0, end = 0, counter = 0, d = 0;
        while(end < s.size()) {
            if(mp[s[end++]]++ == 0) counter++;
            while(counter > 2) {
                if(mp[s[begin++]]-- == 1) counter--;
            }
            d = max(d, end - begin);
        }
        return d;
    }
};
