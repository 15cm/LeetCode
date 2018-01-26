class Solution {
    vector<int> factors = {2, 3, 5};
public:
    bool isUgly(int num) {
        if(num <= 0) return false;
        else if(num == 1) return true;
        else {
            for(int f: factors) {
                if(num % f == 0)
                    return isUgly(num / f);
            }
            return false;
        }
    }
};
