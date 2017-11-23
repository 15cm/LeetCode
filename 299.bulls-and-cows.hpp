class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        vector<int> cnt1(10), cnt2(10);
        int bull = 0;
        for(int i = 0; i < n; i++) {
            char c1 = secret[i], c2 = guess[i];
            if(c1 == c2) {
                bull++;
                cnt1[c1 - '0']--;
                cnt2[c2 - '0']--;
            }
            cnt1[c1 - '0']++;
            cnt2[c2 - '0']++;
        }
        int cow = 0;
        for(int i = 0; i < 10; i++) {
            cow += min(cnt1[i], cnt2[i]);
        }
        return to_string(bull) + "A" +  to_string(cow) + "B";
    }
};
