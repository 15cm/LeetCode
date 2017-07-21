#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.empty()) return ans;
        int i = 0;
        vector<int> count(nums.size(), 1);
        sort(nums.begin(), nums.end());
        for(int j = 1; j < nums.size(); j++) {
            if(nums[j - 1] != nums[j]) {
               nums[++i] = nums[j];
            } else {
                count[i]++;
            }
        }
        nums.resize(i + 1);
        vector<int> stat(nums.size());
        generateSubset(stat, nums.size() - 1, count, nums, ans);
        return ans;
    }
    void generateSubset(vector<int>& stat, int cur, vector<int>& count, vector<int>& uniqNums, vector<vector<int>>& ans) {
        if(cur < 0) {
            vector<int> tmp;
            for(int i = 0; i < uniqNums.size(); i++) {
                for(int j = 0; j < stat[i]; j++) {
                    tmp.push_back(uniqNums[i]);
                }
            }
            ans.push_back(tmp);
            return;
        }
        for(int cnt = 0; cnt <= count[cur]; cnt++) {
            stat[cur] = cnt;
            generateSubset(stat, cur - 1, count, uniqNums, ans);
        }
    }
};
