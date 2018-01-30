class Solution {
    const int bsize = sizeof(int);
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size() - 1;
        int maxn = n / bsize + 1;
        vector<int> bitmap(maxn);
        for(int num: nums) {
            int block = num / bsize, index = num % bsize;
            if(bitmap[block] & (1 << index)) return num;
            bitmap[block] |= (1 << index);
        }
        return -1;
    }
};
