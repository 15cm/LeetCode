class Solution {
    struct Cursor {
        int r, c;
        Cursor(int r, int c): r(r), c(c) {}
    };
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int p = 0;
        Cursor cursor(0, 0);
        int ans = 0;
        int totalLen = 0;
        for(auto& s: sentence) {
            totalLen += s.length() + 1;
        }
        while(cursor.r != rows) {
            if(cursor.c == 0) {
                int tolLen = totalLen - 1;
                int len = sentence[p].length();
                if(cursor.c + tolLen <= cols) {
                    cursor.c += tolLen;
                    ans++;
                } else {
                    if(cursor.c + len > cols) {
                        cursor.c = cols;
                    } else {
                        cursor.c += len;
                        p++;
                    }
                }
            } else {
                int tolLen = totalLen;
                int len = sentence[p].length() + 1;
                int k = (cols - cursor.c) / tolLen;
                if(k > 0) {
                    cursor.c += k * tolLen;
                    ans += k;
                } else {
                    if(cursor.c + len > cols) {
                        cursor.c = cols;
                    } else {
                        cursor.c += len;
                        p++;
                    }
                }
            }
            if(cursor.c == cols) {
                cursor.r++;
                cursor.c = 0;
            }
            if(p == sentence.size()) {
                ans++;
                p = 0;
            }
        }
        return ans;
    }
};
