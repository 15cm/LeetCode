class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty()) return true;
        int l = 0, r = s.length() - 1;
        while(l < r) {
            while(l < r && !isAlphanumeric(s[l])) l++;
            while(l < r && !isAlphanumeric(s[r])) r--;
            if(l >= r) break;
            if(normalize(s[l++]) != normalize(s[r--])) return false;
        }
        return true;
    }
    bool isAlphanumeric(char c) {
        return c >= '0' && c <= '9' || c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
    }
    char normalize(char c) {
        if(c >= 'A' && c <= 'Z') return c - 'A' + 'a';
        return c;
    }
};
