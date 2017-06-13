#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> d;
        for(int i = 0; i < nums.size(); i ++) {
            auto search = d.find(target - nums[i]);
            if(search != d.end()) {
                return vector<int> {search->second, i};
            } else {
                d[nums[i]] = i;
            }
        }
        return vector<int>();
    }
};
