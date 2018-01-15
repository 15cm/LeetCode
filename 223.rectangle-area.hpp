class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        if(A > E) {
            swap(A, E);
            swap(B, F);
            swap(C, G);
            swap(D, H);
        }
        int res = (C-A)*(D-B) + (G-E)*(H-F);
        int ex = 0;
        if(F > D || E > C) {
        } else if(F < B) {
            if(H > B) {
                ex = (min(C, G) - E) * (min(H, D) - B);
            }
        } else {
            ex = (min(C, G) - E) * (min(D, H) - F);
        }
        return res - ex;
    }
};
