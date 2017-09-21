class Solution {
public:
    const string LESS_THAN_20[20] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    const string TENS[10] = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    const string THOUSANDS[4] = {"", "Thousand", "Million", "Billion"};
    string numberToWords(int num) {
        if(num == 0) return "Zero";
        int i = 0;
        string words = "";
        while(num) {
            if(num % 1000)
                words = helper(num % 1000) + THOUSANDS[i] + " " + words;
            num /= 1000;
            i++;
        }
        auto s = words.find_first_not_of(' ');
        if(s == string::npos) return "";
        auto e = words.find_last_not_of(' ');
        int len = e - s + 1;
        return words.substr(s, len);
    }
    string helper(int num) {
        if(num == 0) return "";
        else if(num < 20)
            return LESS_THAN_20[num] + " ";
        else if(num < 100)
            return TENS[num / 10] + " " + helper(num % 10);
        else
            return LESS_THAN_20[num / 100] + " Hundred " + helper(num % 100);
    }
};
