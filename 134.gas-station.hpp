#include <vector>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(gas.empty() || cost.empty()) return -1;
        int sum = 0, total = 0, index = -1;
        for(int i = 0; i < gas.size(); i++) {
            int v = gas[i] - cost[i];
            sum += v;
            total += v;
            if(sum < 0) {
                sum = 0;
                index = i;
            }
        }
        return total >= 0 ? index + 1 : -1;
    }
};
