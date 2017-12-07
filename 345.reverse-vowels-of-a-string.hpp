class Solution {
public:
    string reverseVowels(string s) {
        const unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        for(int i = 0, j = s.length()-1; i < j;) {
            bool iv = vowels.count(tolower(s[i])), jv = vowels.count(tolower(s[j]));
            if(iv && jv) {
                swap(s[i++], s[j--]);
            } else if(!iv && !jv) {
                i++; j--;
            } else if(iv) {
                j--;
            } else {
                i++;
            }
        }
        return s;
    }
};
