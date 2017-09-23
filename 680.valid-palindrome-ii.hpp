class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.length();
        for(int i = 0; i < n / 2; i++) {
            int j = n - 1 - i;
            if(s[i] != s[j])
                return isPalindrome(s, i + 1, j) || isPalindrome(s, i, j - 1);
        }
        return true;
    }
    bool isPalindrome(string& s, int lo, int hi) {
        for(int i = lo, j = hi; i < j; i++, j--) {
            if(s[i] != s[j]) return false;
        }
        return true;
    }
};
