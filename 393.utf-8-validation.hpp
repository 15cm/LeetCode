class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int p = 0;
        int n = data.size();
        while(p < n) {
            char d = getData(data[p]);
            int len = 0;
            if(!(d & 0x80)) {
                p++;
                continue;
            }
            char mask = 0xE0;
            char check = 0xC0;
            for(int i = 1; i <= 3; i++) {
                if(!((d & mask) ^ check)) {
                    len = i;
                    break;
                }
                mask = mask >> 1 | 0x8000000;
                check = check >> 1 | 0x80000000;
            }
            if(len == 0 || p + len >= n) return false;
            p++;
            for(int i = 0; i < len; i++, p++) {
                char x = getData(data[p]);
                if((x & 0xC0) ^ 0x80)
                    return false;
            }
        }
        return true;
    }
    char getData(int x) {
        return x & 0x000000FF;
    }
};
