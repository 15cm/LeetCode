class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.empty()) return 0;
        int exp = 1;
        int R = 10;
        int maxVal = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> aux(n);
        while(maxVal / exp > 0) {
            vector<int> cnt(R + 1);
            for(int num: nums) {
                cnt[num / exp % 10 + 1]++;
            }
            for(int i = 1; i <= R; i++) {
                cnt[i] += cnt[i-1];
            }
            for(int num: nums) {
                aux[cnt[num / exp % 10]++] = num;
            }
            nums = aux;
            exp *= 10;
        }
        int ans = 0;
        for(int i = 1; i < n ; i++) {
            ans = max(ans, nums[i] - nums[i-1]);
        }
        return ans;
    }
};
