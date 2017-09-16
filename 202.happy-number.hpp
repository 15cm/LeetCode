class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> rec;
        while(n != 1) {
            int sum = 0, t = n;
            while(t > 0) {
                sum += pow(t % 10, 2);
                t /= 10;
            }
            n = sum;
            if(rec.count(n)) return false;
            rec.insert(n);
        }
        return true;
    }
};
