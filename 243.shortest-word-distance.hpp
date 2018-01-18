class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int i = -1, j = -1;
        int ans = words.size();
        for(int k = 0; k < words.size(); k++) {
            if(words[k] == word1) {
                i = k;
            } else if(words[k] == word2) {
                j = k;
            }

            if(i != -1 && j != -1) {
                ans = min(ans, abs(i-j));
            }
        }
        return ans;
    }
};
