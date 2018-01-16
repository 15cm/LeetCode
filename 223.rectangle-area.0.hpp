class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int res = (C-A)*(D-B) + (G-E)*(H-F);
        return res - overlapArea(A, C, E, G) * overlapArea(B, D, F, H);
    }
    int overlapArea(int A, int B, int C, int D) {
        if(B < C || A > D)
            return 0;
        return min(B, D) - max(A, C);
    }
};
