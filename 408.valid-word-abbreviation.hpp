class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int m = word.size(), n = abbr.size();
        int i = 0, j = 0;
        while(i < m && j < n) {
            if(abbr[j] >= 'a' && abbr[j] <= 'z') {
                if(word[i++] != abbr[j++]) return false;
            } else if(abbr[j] >= '1' && abbr[j] <= '9'){
                int cnt = 0;
                while(j < n && abbr[j] >= '0' && abbr[j] <= '9') {
                    cnt *= 10;
                    cnt += abbr[j] - '0';
                    j++;
                }
                i += cnt;
            } else {
                return false;
            }
        }
        return i == m && j == n;
    }
};
