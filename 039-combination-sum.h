#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int maxCdt = 0;
        for(int& cdt: candidates) if(cdt > maxCdt) maxCdt = cdt;
    }
    void search(vector<int> cadidates, int* st, int* bounds, int target, vector<vector<int>>& ans) {
    }
};
