#include <typeinfo>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<char> ALPHABET;
        for(int i = 0; i < 26; i ++) {
            ALPHABET.push_back(i + 'a');
        }
        vector<int> ans;
        map<char, vector<string>> initialWords;
        if(words.size() == 0) return ans;
        int wordCnt = words.size();
        int wordLen = words[0].length();

        sort(words.begin(), words.end());
        for(auto& word: words) {
            if(initialWords.find(word[0]) == initialWords.end())
                initialWords[word[0]] = vector<string>();
            initialWords[word[0]].push_back(word);
        }

        for(int index = 0; index <= (int)(s.length() - wordCnt * wordLen); index ++) {
            map<char, vector<string>> initialSubstrings;
            for(int i = 0, initialIndex = index; i < wordCnt; i ++, initialIndex += wordLen) {
                char initial = s[initialIndex];
                if(initialSubstrings.find(initial) == initialSubstrings.end()) {
                    initialSubstrings[initial] = vector<string>();
                }
                initialSubstrings[initial].push_back(s.substr(initialIndex, wordLen));
            }
            bool ok = true;
            for(auto& ch: ALPHABET) {
                if(initialSubstrings.count(ch) != initialWords.count(ch)) {
                    ok = false; break;
                } else if(initialSubstrings.count(ch) > 0 && !checkConcat(initialSubstrings[ch], initialWords[ch])) {
                    ok = false; break;
                }
            }
            if(ok) {
                ans.push_back(index);
            }
        }

        return ans;
    }

    bool checkConcat(vector<string> substrings, vector<string> words) {
        if(substrings.size() != words.size()) return false;
        sort(substrings.begin(), substrings.end());
        for(int i = 0; i < substrings.size(); i ++) {
            if(substrings[i] != words[i]) return false;
        }
        return true;
    }
};
