#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int i = 0, j;
        int n = words.size();
        while(true) {
            j = i;
            int widthLeft = maxWidth, spaceTotal = maxWidth;
            while(j < n) {
                int wordLen = words[j].length();
                if(widthLeft >= wordLen) {
                    widthLeft -= wordLen + 1;
                    spaceTotal -= wordLen;
                    j++;
                } else {
                    break;
                }
            }
            if(j == n) {
                string line = "";
                for(int k = i; k < j; k ++) {
                    line += words[k];
                    if(spaceTotal > 0) {
                        line += ' ';
                        spaceTotal--;
                    }
                }
                while(spaceTotal--) line += ' ';
                ans.push_back(line);
                break;
            }
            int wordCnt = j - i;
            string line = "";
            if(wordCnt == 1) {
                line += words[i];
                line.append(spaceTotal, ' ');
            } else {
                int eachSpaceCnt = spaceTotal / (wordCnt - 1), extraSpaceCnt = spaceTotal % (wordCnt - 1);
                for(int k = i; k < j - 1; k ++) {
                    line += words[k];
                    line.append(eachSpaceCnt, ' ');
                    if(extraSpaceCnt > 0) {
                        line += ' ';
                        extraSpaceCnt--;
                    }
                }
                line += words[j - 1];
            }
            ans.push_back(line);
            i = j;
        }
        return ans;
    }
};
