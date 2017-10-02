class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.length();
        for(int i = (n-1)/2; i >= 0; i--) {
            int len1 = expand(i, i, s);
            int len2 = expand(i, i + 1, s);
            int len = max(len1, len2);
            int start = i - (len-1)/2;
            if(start == 0) {
                string t = s.substr(start + len);
                reverse(t.begin(), t.end());
                return t + s;
            }
        }
        return "";
    }
    int expand(int left, int right, string& s) {
        while(left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }
};
