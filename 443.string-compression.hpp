class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int n = chars.size();
        for(int j = 0, k = 0; j < n; j = k) {
            while(k < n && chars[k] == chars[j]) k++;
            int len = k - j;
            chars[i++] = chars[j];
            if(len > 1) {
                int exp = 1;
                for(int x = len; x >= 10; x /= 10) exp *= 10;
                while(exp) {
                    chars[i++] = len / exp + '0';
                    len %= exp;
                    exp /= 10;
                }
            }
        }
        return i;
    }
};
