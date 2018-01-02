#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if(nums.empty()) return "";
        vector<string> arr;
        for(int x: nums) {
            arr.push_back(to_string(x));
        }
        sort(arr.begin(), arr.end(), [](const auto& s, const auto& t) {
                                         return s + t > t + s;
                                     });
        string s;
        for(auto& t: arr) {
            s += t;
        }
        if(s[0] == '0') return "0";
        return s;
    }
};
