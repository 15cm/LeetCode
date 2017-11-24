class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        int n = flowers.size();
        if(k + 2 > n) return -1;
        vector<int> f(n);
        for(int i = 0; i < n; i++)
            f[flowers[i] - 1] = i + 1;

        int ans = n + 1;

        deque<int> q;
        for(int i = 0; i < n - 1; i++) {
            int start = i - k + 1;
            if(k > 0) {
                while(!q.empty() && q.front() < start) q.pop_front();
                while(!q.empty() && f[q.back()] > f[i]) q.pop_back();
                q.push_back(i);
            }
            if(start > 0) {
                int left = start - 1, right = i + 1;
                int gtDay = max(f[left], f[right]);
                if(k == 0 || f[q.front()] > gtDay)
                    ans = min(ans, gtDay);
                cout << gtDay << endl;
            }
        }
        return ans == n + 1 ? -1 : ans;
    }
};
