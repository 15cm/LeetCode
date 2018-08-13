struct Range {
    int l, r;
    Range(int l, int r): l(l), r(r) {}
    bool operator < (const Range &range) const {
        return l < range.l;
    }
};

class Solution {
public:
    string boldWords(vector<string>& words, string S) {
        vector<Range> ranges;
        for(string &word: words)
            findRanges(word, S, ranges);
        if(ranges.empty()) return S;
        sort(ranges.begin(), ranges.end());
        int n = mergeRanges(ranges);
        string ans;
        int i = 0;
        for(int j = 0; j < S.size(); j++) {
            if(i >= n) {
                ans += S.substr(j);
                break;
            }
            if(ranges[i].l == j)
                ans += "<b>";
            ans.push_back(S[j]);
            if(ranges[i].r == j) {
                ans += "</b>";
                i++;
            }
        }
        return ans;
    }
    void findRanges(string &word, string &s, vector<Range> &ranges) {
        int len = word.size();
        int p = s.find(word);
        while(p != string::npos) {
            ranges.emplace_back(p, p + len - 1);
            p = s.find(word, p + 1);
        }
    }
    int mergeRanges(vector<Range> &ranges) {
        int i = 0;
        for(int j = 1; j < ranges.size(); j++) {
            if(ranges[j].l > ranges[i].r + 1) {
                ranges[++i] = ranges[j];
            } else {
                ranges[i].r = max(ranges[i].r, ranges[j].r);
            }
        }
        return i + 1;
    }
};
