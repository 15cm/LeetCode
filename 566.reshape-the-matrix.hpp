class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if(nums.empty() || nums[0].empty()) return nums;
        int m = nums.size(), n = nums[0].size();
        if(m * n != r * c) return nums;
        vector<vector<int>> matrix(r, vector<int>(c));
        int x = 0, y = 0;
        for(auto &vec: nums)
            for(auto num: vec) {
                matrix[x][y] = num;
                if(++y == c) {
                    x++;
                    y = 0;
                }
            }
        return matrix;
    }
};
