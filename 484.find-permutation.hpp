class Solution {
public:
    vector<int> findPermutation(string s) {
        int n = s.length();
        vector<int> ans(n+1);
        ans[0] = 1;
        for(int i = 1; i <= n;) {
            ans[i] = i+1;
            int j = i;
            if(s[i-1] == 'D') {
                while(i <= n && s[i-1] == 'D') i++;
                for(int k = j-1, l = i; k < i; k++, l--)
                    ans[k] = l;
            } else {
                i++;
            }
        }
        return ans;
    }
};
