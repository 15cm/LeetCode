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
                int l = i;
                while(len) {
                    chars[l++] = len % 10 + '0';
                    len /= 10;
                }
                for(int p = i, q = l-1; p < q; p++, q--) swap(chars[p], chars[q]);
                i = l;
            }
        }
        return i;
    }
};
