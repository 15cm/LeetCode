class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> cnts(26), cntp(26);
        int n = s.length(), m = p.length();
        for(auto c: p) cntp[c-'a']++;

        vector<int> ans;
        for(int i = 0; i < n; i++) {
            cnts[s[i]-'a']++;
            if(i >= m) {
                cnts[s[i-m]-'a']--;
            }
            if(i >= m-1 && cnts == cntp) {
                ans.push_back(i+1-m);
            }
        }
        return ans;
    }
};
