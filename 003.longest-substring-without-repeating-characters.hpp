class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mp(128, 0);
        int i = 0, j = 0, counter = 0, d = 0;
        while(j < s.size()) {
            if(mp[s[j++]]++ == 1) counter++;
            while(counter) {
                if(mp[s[i++]]-- == 2) counter--;
            }
            d = max(d, j - i);
        }
        return d;
    }
};
