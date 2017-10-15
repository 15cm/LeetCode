class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size();
        int h = 0;
        for(int i = n - 1; i >= 0; i--) {
            int cnt = n - i;
            if(citations[i] >= cnt &&  (i == 0 || citations[i-1] <= cnt)) {
                h = max(h, cnt);
            }
        }
        return h;
    }
};
