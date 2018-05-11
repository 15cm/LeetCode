class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num <= 2) return false;
        int sum = 1;
        int i = 2;
        for(; i * i < num; i++) {
            if(num % i == 0) {
                sum += i + num / i;
            }
        }
        if(i * i == num) sum += i;
        return sum == num;
    }
};
