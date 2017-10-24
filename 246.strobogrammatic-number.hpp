class Solution {
    const int mp[10] = {0, 1, -1, -1, -1, -1, 9, -1, 8, 6};
public:
    bool isStrobogrammatic(string num) {
        int n = num.length();
        for(int i = 0, j = n - 1; i <= j; i++, j--) {
            if(i != j) {
                if(mp[num[i] - '0'] != num[j] - '0') return false;
            } else {
                return num[i] == '0' || num[i] == '1' || num[i] == '8';
            }
        }
        return true;
    }
};
