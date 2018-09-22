class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        if(m + n == 0) return "";
        vector<int> sum(m + n);
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                sum[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
        for(int i = m + n - 1; i > 0; i--) {
            sum[i - 1] += sum[i] / 10;
            sum[i] %= 10;
        }
        string ans;
        int i = 0;
        while(i < m + n && sum[i] == 0) i++;
        for(; i < m + n; i++)
            ans.push_back(sum[i] + '0');
        return ans.empty() ? "0" : ans;
    }
};
