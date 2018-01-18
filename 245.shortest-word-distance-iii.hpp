class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int i = -1, j = -1;
        int ans = words.size();
        bool flag = word1 == word2;
        for(int k = 0; k < words.size(); k++) {
            if(flag) {
                if(words[k] == word1) {
                    if(i == -1) {
                        i = k;
                    } else if (j == -1) {
                        j = k;
                    } else {
                        i = j;
                        j = k;
                    }
                }
            } else {
                if(words[k] == word1) {
                    i = k;
                } else if(words[k] == word2)
                    j = k;
            }

            if(i != -1 && j != -1) {
                ans = min(ans, abs(i-j));
            }
        }
        return ans;
    }
};
