class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        string s;
        for(string &st: sentence) {
            s += st;
            s.push_back(' ');
        }
        int n = s.size();
        int cur = 0;
        for(int i = 0; i < rows; i++) {
            cur += cols;
            if(s[cur % n] == ' ') {
                cur++;
            } else {
                while(cur > 0 && s[(cur - 1) % n] != ' ')
                    cur--;
            }
        }
        return cur / n;
    }
};
