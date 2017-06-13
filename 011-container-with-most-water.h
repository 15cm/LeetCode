#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        for(int i = 0, j = height.size() - 1; i < j;height[i] > height[j] ? j -- : i ++) {
            ans = max(ans, areaOf(i, j, height[i], height[j]));
        }
        return ans;
    }
    int areaOf(int left, int right, int h1, int h2) {
        return min(h1, h2) * (right - left);
    }
};
