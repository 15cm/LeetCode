class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        if(p1 == p2 && p2 == p3 && p3 == p4 && p4 == p1) return false;
        return check({p1, p2, p3, p4}) ||
            check({p1, p2, p4, p3}) ||
            check({p1, p3, p2, p4}) ||
            check({p1, p3, p4, p2}) ||
            check({p1, p4, p2, p3}) ||
            check({p1, p4, p3, p2}) ;
    }
    bool check(const vector<vector<int>> &points) {
        int len = lenSquare(points[0], points[3]);
        for(int i = 0; i < 3; i++) {
            if(lenSquare(points[i], points[i+1]) != len) return false;
        }
        return lenSquare(points[0], points[2]) == lenSquare(points[1], points[3]);
    }
    int lenSquare(const vector<int>& p1, const vector<int>& p2) {
        return pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2);
    }
};
