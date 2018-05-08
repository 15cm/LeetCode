class Solution {
    vector<int> tree;
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        tree = vector<int>(n+1);
        int ans = 0;

        auto aux = nums;
        sort(aux.begin(), aux.end());

        for(int i = n - 1; i >= 0; i--) {
            int j = lower_bound(aux.begin(), aux.end(), nums[i] >= 0 ? (nums[i] + 1) / 2 : nums[i] / 2) - aux.begin();
            if(j > 0)
                ans += getSum(j-1);
            update(lower_bound(aux.begin(), aux.end(), nums[i]) - aux.begin(), 1);
        }
        return ans;
    }
    int lowbit(int x) {
        return x & (-x);
    }
    int getSum(int index) {
        index++;
        int sum = 0;
        while(index > 0) {
            sum += tree[index];
            index -= lowbit(index);
        }
        return sum;
    }
    void update(int index, int inc) {
        index++;
        while(index < tree.size()) {
            tree[index] += inc;
            index += lowbit(index);
        }
    }
};
