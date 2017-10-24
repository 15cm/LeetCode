class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        if(words.empty() || words[0].empty()) return true;
        int m = words.size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < words[i].length(); j++) {
                if(i >= words[j].length() || j >= m || words[i][j] != words[j][i])
                    return false;
            }
        }
        return true;
    }
};
