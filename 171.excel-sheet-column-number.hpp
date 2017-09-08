class Solution {
public:
    int titleToNumber(string s) {
        int num = 0;
        for(auto t: s) {
            num *= 26;
            num += t - 'A' + 1;
        }
        return num;
    }
};
