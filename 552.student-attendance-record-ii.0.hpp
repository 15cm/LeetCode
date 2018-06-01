#define LL long long
class Solution {
public:
    // based on state machine
    int checkRecord(int n) {
        LL M = 1e9 + 7;
        LL a0l0, a0l1, a0l2, a1l0, a1l1, a1l2;
        a0l0 = 1;
        a0l1 = a0l2 = a1l0 = a1l1 = a1l2 = 0;
        for(int i = 0; i < n; i++) {
            LL n_a0l0 = (a0l0 + a0l1 + a0l2) % M;
            LL n_a0l1 = a0l0;
            LL n_a0l2 = a0l1;
            LL n_a1l0 = (n_a0l0 + a1l0 + a1l1 + a1l2) % M;
            LL n_a1l1 = a1l0;
            LL n_a1l2 = a1l1;
            a0l0 = n_a0l0;
            a0l1 = n_a0l1;
            a0l2 = n_a0l2;
            a1l0 = n_a1l0;
            a1l1 = n_a1l1;
            a1l2 = n_a1l2;
        }
        return (a0l0 + a0l1 + a0l2 + a1l0 + a1l1 + a1l2) % M;
    }
};
