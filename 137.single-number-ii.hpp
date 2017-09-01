class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0;
        int b = 0;
        for(int c: nums) {
            int ta = b&c | a&~c;
            b = ~a&~b&c | b&~c;
            a = ta;
        }
        return b;
    }
};
