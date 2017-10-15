class Solution {
public:
    string nearestPalindromic(string n) {
        int k = n.length();
        if(k == 1) return to_string(stoi(n) - 1);

        vector<string> candidates = {getNines(k-1) , getOneZeros(k)};
        getCandidates(candidates, n);

        string ans;
        long diff = LONG_MAX;
        for(string candidate: candidates) {
            if(candidate == n)
                continue;
            long tmp = labs(stol(candidate) - stol(n));
            if(tmp < diff) {
                diff = tmp;
                ans = candidate;
            }
        }
        return ans;
    }

    string getNines(int k) {
        return string(k, '9');
    }
    string getOneZeros(int k) {
        return "1" + string(k - 1, '0') + "1";
    }
    void getCandidates(vector<string>& ans, string n) {
        int len = n.length();
        string n1 = n.substr(0, (len+1) / 2);
        long num = stol(n1);
        vector<long> arr = {num - 1, num, num + 1};
        for(long ele: arr) {
            string n2 = to_string(ele);
            if(len % 2 == 1) {
                n2 = n2.substr(0, n2.length() - 1);
            }
            reverse(n2.begin(), n2.end());
            ans.push_back(to_string(ele) + n2);
        }
    }
};
