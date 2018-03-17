class Solution {
    const string HEX = "0123456789abcdef";
public:
    string toHex(int num) {
        if(num == 0) return "0";
        string s;
        unsigned int x = num;
        while(x) {
            s.push_back(HEX[x & 0xF]);
            x >>= 4;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};
