#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0;
        int ans = 0;
        int cur = 0;
        while(true) {
            if(height[cur] == 0) {
                cur++;
                continue;
            }
            int next = nextBar(cur, height);
            if(next >= height.size()) break;
            ans += compute(cur, next, height);
            cur = next;
        }
        return ans;
    }

    int nextBar(int cur, vector<int>& height) {
        int ltMax = 0, ltMaxIndex = height.size();
        for(int i = cur + 1; i < height.size(); i ++) {
            if(height[i] >= height[cur]) return i;
            else if(height[i] > ltMax) {
                ltMax = height[i];
                ltMaxIndex = i;
            }
        }
        return ltMaxIndex;
    }

    int compute(int left, int right, vector<int>& height) {
        int h = min(height[left], height[right]);
        int area = (right - left) * h;
        for(int i = left; i < right; i ++) {
            area -= min(h, height[i]);
        }
        return area;
    }
};
