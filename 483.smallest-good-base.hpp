#define LL long long
class Solution {
public:
    string smallestGoodBase(string n) {
        LL num = stoll(n);
        for(int k = 63; k >= 2; k--) {
            LL x = floor(pow(num, 1.0/k));
            if(x < 2) continue;
            LL sum = 1;
            for(int i = 0; i < k; i++)
                sum = sum * x + 1;
            if(sum == num)
                return to_string(x);
        }
        return to_string(num-1);
    }
};
