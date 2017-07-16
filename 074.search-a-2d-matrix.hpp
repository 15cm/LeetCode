#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rl = 0, rr = matrix.size();
        if(matrix.empty() || matrix[0].empty() || target < matrix[0][0]) return false;
        while(rl < rr) {
            int rm = (rl + rr) / 2;
            if(target < matrix[rm][0]) rr = rm;
            else if(target > matrix[rm][0]) rl = rm + 1;
            else return true;
        }
        int r = rl - 1, cl = 0, cr = matrix[0].size();
        while(cl < cr) {
            int cm = (cl + cr) / 2;
            if(target < matrix[r][cm]) cr = cm;
            else if(target > matrix[r][cm]) cl = cm + 1;
            else return true;
        }
        return false;
    }
};
