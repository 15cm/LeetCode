class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<string> ans;
        for(int i = 0, k, l; i < n; i += k) {
            for(k = 0, l = 0; i + k < n && l + words[i+k].length() <= maxWidth - k; k++) {
                l += words[i+k].length();
            }
            string s = words[i];
            for(int j = 0; j < k - 1; j++) {
                if(i + k >= n) s.push_back(' ');
                else {
                    int spaces = maxWidth - l;
                    s.append(spaces / (k - 1) + (j < spaces % (k - 1)), ' ');
                }
                s += words[i+j+1];
            }
            s.append(maxWidth - s.length(), ' ');
            ans.push_back(s);
        }
        return ans;
    }
};
