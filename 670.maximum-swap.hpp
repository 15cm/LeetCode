class Solution {
public:
    int maximumSwap(int num) {
        stack<int> stk;
        vector<int> digits;
        while(num) {
            digits.push_back(num % 10);
            num /= 10;
        }
        int n = digits.size();
        stk.push(0);
        for(int i = 1; i < n; i++) {
            int maxIdx = stk.top();
            if(digits[i] > digits[maxIdx]) {
                maxIdx = i;
            }
            stk.push(maxIdx);
        }
        int ans = 0;
        bool hasSwapped = false;
        for(int i = n - 1; i >= 0; i--) {
            int maxIdx = stk.top(); stk.pop();
            if(!hasSwapped && i != maxIdx && digits[i] < digits[maxIdx]) {
                swap(digits[i], digits[maxIdx]);
                hasSwapped = true;
            }
            ans = ans * 10 + digits[i];
        }
        return ans;
    }
};
