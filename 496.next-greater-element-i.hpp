class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = findNums.size(), m = nums.size();
        for(int i = 0; i < m; i++) {
            mp[nums[i]] = -1;
            for(int j = i + 1; j < m; j++) {
                if(nums[j] > nums[i]) {
                    mp[nums[i]] = nums[j];
                    break;
                }
            }
        }
        for(int& x: findNums) {
            x = mp[x];
        }
        return findNums;
    }
};
