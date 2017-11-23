class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        list<char> ans;
        int n = S.length();
        for(int i = n - 1, cnt = 0; i >= 0; i--) {
            if(cnt == K) {
                ans.push_front('-');
                cnt = 0;
            }
            if(S[i] != '-') {
                ans.push_front(toupper(S[i]));
                cnt++;
            }
        }
        if(*ans.begin() == '-') ans.pop_front();
        return string(ans.begin(), ans.end());
    }
};
