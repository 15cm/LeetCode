class Solution {
public:
    int thirdMax(vector<int>& nums) {
        vector<int> maxs(3, INT_MIN);
        bool vis[3] = {false};
        for(int num: nums) {
            for(int i = 0; i < maxs.size(); i++) {
                if(num >= maxs[i]) {
                    if(num > maxs[i]) {
                        for(int j = 1; j >= 0; j--) {
                            if(i+j+1 < maxs.size() && vis[i+j]) {
                                maxs[i+j+1] = maxs[i+j];
                                vis[i+j+1] = true;
                            }
                        }
                        maxs[i] = num;
                    }
                    vis[i] = true;
                    break;
                }
            }
        }
        return vis[2] ? maxs[2] : maxs[0];
    }
};
