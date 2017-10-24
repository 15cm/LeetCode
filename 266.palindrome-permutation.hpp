class Solution {
public:
    bool canPermutePalindrome(string s) {
        int cnt[128] = {0};
        for(char c: s) {
            cnt[c]++;
        }
        int singles = 0;
        for(int c: cnt) {
            if(c % 2 != 0 && ++singles > 1) return false;
        }
        return true;
    }
};
