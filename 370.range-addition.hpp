#define lson l, m, d << 1
#define rson m+1, r, d << 1 | 1
class Solution {
    int* tree;

    void add(int L, int R, int c, int l, int r, int d) {
        if(L > r || R < l) return;
        if(L <= l && R >= r) {
            tree[d] += c;
            return;
        }
        int m = l + (r - l)/2;
        if(L <= m) add(L, R, c, lson);
        if(R > m) add(L, R, c, rson);
    }

    void query(int p, int l, int r, int d, int& sum) {
        sum += tree[d];
        if(l == r) return;
        int m = l + (r-l)/2;
        if(p <= m) {
            query(p, lson, sum);
        } else {
            query(p, rson, sum);
        }
    }
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        int N = (length + 1) << 2;
        tree = new int[N];
        memset(tree, 0, N * sizeof(*tree));
        int left = 0, right = length - 1;
        for(auto& u: updates) {
            add(u[0], u[1], u[2], left, right, 1);
        }
        vector<int> ans(length);
        for(int i = 0; i < length; i++) {
            int sum = 0;
            query(i, left, right, 1, sum);
            ans[i] = sum;
        }
        return ans;
    }
};
