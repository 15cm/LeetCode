#include <list>
#include <string>
using namespace std;
class Solution {
public:
    // Extra Space
    // void reverseWords(string &s) {
    //     list<string> words;
    //     int n = s.length();
    //     for(int i = 0; i < n;) {
    //         while(i < n && s[i] == ' ') i++;
    //         if(i == n) break;
    //         int j = i;
    //         while(i < n && s[i] != ' ') i++;
    //         words.push_front(s.substr(j, i - j));
    //     }
    //     s.clear();
    //     for(auto it = words.begin(); it != words.end(); it++) {
    //         if(it == words.begin()) s += *it;
    //         else s += " " + *it;
    //     }
    // }

    // In place
    void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        int n = s.length();
        int wordEnd = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] != ' ') {
                if(wordEnd != 0) s[wordEnd++] = ' ';
                int j = i;
                while(j < n && s[j] != ' ') s[wordEnd++] = s[j++];
                reverse(s.begin() + wordEnd - (j - i), s.begin() + wordEnd);
                i = j;
            }
        }
        s.erase(s.begin() + wordEnd, s.end());
    }
};
