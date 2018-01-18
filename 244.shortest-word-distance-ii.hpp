class WordDistance {
    unordered_map<string, vector<int>> mp;
    int maxDis;
public:
    WordDistance(vector<string> words) {
        for(int i = 0; i < words.size(); i++) {
            mp[words[i]].push_back(i);
        }
        maxDis = words.size();
    }
    
    int shortest(string word1, string word2) {
        auto &v1 = mp[word1], &v2 = mp[word2];
        int ans = maxDis;
        for(int i = 0, j = 0; i < v1.size() || j < v2.size();) {
            int dis;
            if(i >= v1.size()) {
                dis = abs(v1.back() - v2[j++]);
            } else if (j >= v2.size()){
                dis = abs(v2.back() - v1[i++]);
            } else {
                dis = abs(v1[i] - v2[j]);
                if(v1[i] < v2[j]) {
                    i++;
                } else {
                    j++;
                }
            }
            ans = min(ans, dis);
        }
        return ans;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */
