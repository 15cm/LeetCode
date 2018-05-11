class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0) return "0";
        string ans;
        int n = abs(num);
        while(n) {
            int quo = n / 7, rem = n % 7;
            ans.push_back(rem + '0');
            n = quo;
        }
        if(num < 0) ans.push_back('-');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
