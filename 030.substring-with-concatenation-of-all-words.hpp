class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(words.empty()) return {};
        int len = words[0].size();
        unordered_map<string, int> dict;
        for(auto &word: words) dict[word]++;
        vector<int> ans;
        for(int k = 0; k < len; k++) {
            unordered_map<string, int> local_dict;
            int cnt = 0;
            for(int i = k, j = k; j < s.size(); j += len) {
                if((j - i) / len >= words.size()) {
                    string remove_word = s.substr(i, len);
                    if(dict.count(remove_word)) {
                        if(local_dict[remove_word]-- <= dict[remove_word])
                            cnt--;
                    }
                    i += len;
                }
                string add_word = s.substr(j, len);
                if(dict.count(add_word)) {
                    if(++local_dict[add_word] <= dict[add_word])
                        cnt++;
                }
                if(cnt == words.size())
                    ans.push_back(i);
            }
        }
        return ans;
    }

};
