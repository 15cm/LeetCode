class Solution {
    struct Node {
        char c;
        int f;
        Node(char c, int f): c(c), f(f) {}
        bool operator < (const Node& rhs) const {
            return f < rhs.f;
        }
    };
public:
    string rearrangeString(string s, int k) {
        if(k == 0) return s;
        int cnt[26] = {0};
        for(char c: s) cnt[c-'a']++;
        int n  = s.length();

        priority_queue<Node> pq;
        vector<vector<char>> next(n);
        for(int i = 0; i < 26; i++)
            if(cnt[i] > 0)
                next[0].push_back(i+'a');
        for(int i = 0; i < n; i++) {
            if(!next[i].empty())
                for(char c: next[i])
                    pq.push(Node(c, cnt[c-'a']));
            if(pq.empty()) return "";
            char c = pq.top().c; pq.pop();
            s[i] = c;
            if(--cnt[c-'a'] > 0 && i + k < n)
                next[i+k].push_back(c);
        }
        return s;
    }
};
