// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
    int buffPtr = 0, buffCnt = 0;
    char buff[4];
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int ptr = 0;
        while(ptr < n) {
            if(buffPtr == 0) {
                buffCnt = read4(buff);
            }
            if(buffCnt == 0) break;
            while(ptr < n && buffPtr < buffCnt) {
                buf[ptr++] = buff[buffPtr++];
            }
            if(buffPtr == buffCnt)
                buffPtr = 0;
        }
        return ptr;
    }
};
