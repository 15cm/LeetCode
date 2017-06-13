#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        while(n-- > 1) ans = nextSeq(ans);
        return ans;
    }
    string nextSeq(const string& str) {
        if(str.length() == 1) return "11";
        int num = 1, i = 0;
        string ans = "";
        while(true) {
            while(i < str.length() - 1 && str[i] == str[i + 1]) {
                num++;
                i++;
            }
            if(i == str.length() - 1) break;
            ans.append(to_string(num));
            ans.append(1, str[i]);
            i ++;
            num = 1;
        }
        if(str[i] == str[i-1]) {
            ans.append(to_string(num));
            ans.append(1, str[i]);
        } else {
            ans.append(1, '1');
            ans.append(1, str[i]);
        }
        return ans;
    }
};
