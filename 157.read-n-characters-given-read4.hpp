// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int total = 0;
        char tmp[4];
        bool eof = false;
        while(!eof && total < n) {
            int cnt = read4(tmp);
            eof = (cnt < 4);
            int len = min(cnt, n - total);
            for(int i = 0; i < len; i++)
                buf[total + i] = tmp[i];
            total += len;
        }
        return total;
    }
};
