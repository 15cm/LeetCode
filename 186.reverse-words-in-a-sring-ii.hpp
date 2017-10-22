class Solution {
public:
    void reverseWords(vector<char>& str) {
        reverse(str.begin(), str.end());
        int n = str.size();
        for(int i = 0, j = 0; i < n; i = j + 1) {
            for(j = i; j < n && str[j] != ' '; j++);
            reverse(str.begin() + i, str.begin() + j);
        }
    }
};
