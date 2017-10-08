class Solution {
    const string LT_10[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    const string LT_20[10] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    const string LT_100[8] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    const string THOUSANDS[4] = {"", "Thousand", "Million", "Billion"};
public:
    string numberToWords(int num) {
        if(num == 0) return LT_10[0];
        string ans;
        int i = 0;
        while(num) {
            if(num % 1000 != 0) {
                ans = helper(num % 1000) + THOUSANDS[i] + " " + ans;
            }
            num /= 1000;
            i++;
        }
        ans.erase(find_if(ans.rbegin(), ans.rend(), [](char c) {
                    return c != ' ';
                }).base(), ans.end());
        return ans;
    }
    string helper(int num) {
        string s;
        while(num) {
            if(num < 10) {
                s += LT_10[num] + " ";
                break;
            } else if(num < 20) {
                s += LT_20[num - 10] + " ";
                break;
            } else if(num < 100) {
                s += LT_100[(num - 20) / 10] + " ";
                num = num % 10;
            } else {
                s += LT_10[num / 100] + " Hundred ";
                num = num % 100;
            }
        }
        return s;
    }
};
