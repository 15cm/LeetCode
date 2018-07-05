class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> q;
        int cnt[2] = {0}, ban[2] = {0};
        for(char c: senate) {
            int x = (c == 'R' ? 0 : 1);
            cnt[x]++;
            q.push(x);
        }
        while(cnt[0] && cnt[1]) {
            int x = q.front(); q.pop();
            if(ban[x]) {
                ban[x]--;
                cnt[x]--;
            } else {
                ban[x^1]++;
                q.push(x);
            }
        }
        return cnt[0] ? "Radiant" : "Dire";
    }
};
