class Solution {
public:
    string nextClosestTime(string time) {
        unordered_set<int> digits;
        for(char c: time)
            if(c >= '0' && c <= '9') digits.insert(c - '0');
        int colon = time.find(":");
        string hh = time.substr(0, colon);
        string mm = time.substr(colon + 1);
        int start = stoi(hh) * 60 + stoi(mm);
        int ans = 24 * 60;
        string res = time;

        for(int h1: digits)
            for(int h2: digits)
                if(h1 * 10 + h2 < 24) {
                    for(int m1: digits)
                        for(int m2: digits)
                            if(m1 * 10 + m2 < 60) {
                                int cur = (h1 * 10 + h2) * 60 + (m1 * 10 + m2);
                                int elapsed = (cur - start + 24 * 60) % (24 * 60);
                                if(elapsed > 0 && elapsed < ans) {
                                    ans = elapsed;
                                    char buf[6];
                                    snprintf(buf, sizeof(buf), "%02d:%02d", h1 * 10 + h2, m1 * 10 + m2);
                                    res = buf;
                                }
                            }
                }
        return res;
    }
};
