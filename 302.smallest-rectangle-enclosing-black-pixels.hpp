class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        if(image.empty() || image[0].empty()) return 0;
        int m = image.size(), n = image[0].size();
        int left = searchCols(0, y, 0, m, true, image);
        int right = searchCols(y+1, n, 0, m, false, image);
        int top = searchRows(0, x, left, right, true, image);
        int bottom = searchRows(x+1, m, left, right, false, image);
        return (right - left) * (bottom - top);
    }
    int searchCols(int i, int j, int top, int bottom, bool whiteToBlack, vector<vector<char>>& image) {
        while(i < j) {
            int k = top, mid = i+(j-i)/2;
            while(k < bottom && image[k][mid] == '0') k++;
            if(k < bottom == whiteToBlack) {
                j = mid;
            } else {
                i = mid + 1;
            }
        }
        return i;
    }
    int searchRows(int i, int j, int left, int right, bool whiteToBlack, vector<vector<char>>& image) {
        while(i < j) {
            int k = left, mid = i+(j - i)/2;
            while(k < right && image[mid][k] == '0') k++;
            if(k < right == whiteToBlack) {
                j = mid;
            } else {
                i = mid + 1;
            }
        }
        return i;
    }
};
