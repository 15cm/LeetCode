class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        if(n == 0) return 0;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) {
            for(char c: words[i]) {
                arr[i] |= (1 << (c - 'a'));
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++) {
                if((arr[i] & arr[j]) == 0)
                    ans = max(ans, (int)words[i].length() * (int)words[j].length());
            }
        return ans;
    }
};
