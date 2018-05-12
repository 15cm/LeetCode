class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        int lowerCnt = 0, upperCnt = 0;
        for(char c: word)
            if(islower(c))
                lowerCnt++;
            else
                upperCnt++;
        return upperCnt == n || lowerCnt == n || isupper(word[0]) && upperCnt == 1;
    }
};
