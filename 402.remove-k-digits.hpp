class Solution {
public:
    string removeKdigits(string num, int k) {
        while(k-- && !num.empty()) {
            int p = 0;
            while(p+1 < num.size() && num[p+1] >= num[p]) p++;
            int c = 1;
            if(p == 0) {
                while(p+c < num.size() && num[p+c] == '0') c++;
            }
            num.erase(p, c);
        }
        return num.empty() ? "0" : num;
    }
};
