class Solution {
public:
    int addDigits(int num) {
        while(num/10 > 0) {
            int sum = 0;
            for(int x = num; x > 0; x /= 10) {
                sum += x % 10;
            }
            num = sum;
        }
        return num;
    }
};
