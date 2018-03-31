class Solution {
    const string mp[10] = {
        "zero",
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine"
    };
public:
    string
    originalDigits(string s) {
        int cnt[10] = {0};
        int idx;
        for(auto c: s) {
            switch(c) {
            case 'z': idx = 0; break;
            case 'w': idx = 2; break;
            case 'u': idx = 4; break;
            case 'x': idx = 6; break;
            case 'g': idx = 8; break;
            case 'f': idx = 5; break; //5-4
            case 's': idx = 7; break; //7-6
            case 'h': idx = 3; break; //3-8
            case 'i': idx = 9; break; //9-8-6-5
            case 'o': idx = 1; break; //1-0-2-4
            default: idx = -1;
            };
            if(idx >= 0)
                cnt[idx]++;
        }
        cnt[5] -= cnt[4];
        cnt[7] -= cnt[6];
        cnt[3] -= cnt[8];
        cnt[9] -= cnt[8] + cnt[6] + cnt[5];
        cnt[1] -= cnt[0] + cnt[2] + cnt[4];
        string ans;
        for(int i = 0; i < 10; i++) {
            ans.append(cnt[i], i + '0');
        }
        return ans;
    }
};
