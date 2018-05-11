class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for(int i = 0; i < n; i++)
            mp[nums[i]] = i;
        for(int& x: findNums) {
            bool ok = false;
            for(int i = mp[x] + 1; i < n; i++) {
                if(nums[i] > x) {
                    ok = true;
                    x = nums[i];
                    break;
                }
            }
            if(!ok) x = -1;
        }
        return findNums;
    }
};
