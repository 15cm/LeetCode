class Solution {
public:
    int magicalString(int n) {
        if(n == 0) return 0;
        if(n <= 3) return 1;

        vector<int> a(n);
        a[0] = 1; a[1] = a[2] = 2;
        int ans = 1;
        for(int hd = 2, tl = 3, cur = 1; tl < n; hd++, cur ^= 3) {
            for(int i = 0; i < a[hd] && tl < n; i++) {
                ans += (cur == 1);
                a[tl++] = cur;
            }
        }
        return ans;
    }
};
