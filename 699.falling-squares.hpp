#define lson(x) (x << 1)
#define rson(x) ((x << 1) | 1)

class SegmentTree {
    int n;
public:
    SegmentTree(int n) {
        this->n = n;
        int N = (n + 1) << 2;
        node = new int[N];
        lazy = new int[N];
        fill(node, node + N, 0);
        fill(lazy, lazy + N, 0);
    }

    void update(int b, int e, int v) {
        update(1, 0, n - 1, b, e, v);
    }

    int query(int b, int e) {
        return query(1, 0, n - 1, b, e);
    }

    ~SegmentTree() {
        delete[] node;
        delete[] lazy;
    }

private:
    int *node, *lazy;

    void pushUp(int u) {
        node[u] = max(node[lson(u)], node[rson(u)]);
    }

    void pushDown(int u) {
        if(lazy[u]) {
            int ls = lson(u), rs = rson(u);
            node[ls] = max(node[ls], lazy[u]);
            lazy[ls] = max(lazy[ls], lazy[u]);
            node[rs] = max(node[rs], lazy[u]);
            lazy[rs] = max(lazy[rs], lazy[u]);
            lazy[u] = 0;
        }
    }

    void update(int u, int l, int r, int b, int e, int v) {
        if(b <= l && e >= r) {
            node[u] = lazy[u] = v;
            return;
        }
        pushDown(u);
        int m = l + (r - l) / 2;
        if(b <= m) {
            update(lson(u), l, m, b, e, v);
        }
        if(e > m) {
            update(rson(u), m + 1, r, b, e, v);
        }
        pushUp(u);
    }

    int query(int u, int l, int r, int b, int e) {
        if(b <= l && e >= r) {
            return node[u];
        }
        pushDown(u);
        int m = l + (r - l) / 2;
        int res = 0;
        if(b <= m) {
            res = max(res, query(lson(u), l, m, b, e));
        }
        if(e > m) {
            res = max(res, query(rson(u), m + 1, r, b, e));
        }
        return res;
    }
};

class Solution {
public:
    vector<int> fallingSquares(vector<pair<int, int>>& positions) {
        vector<int> xs;
        for(auto &pos: positions) {
            xs.push_back(pos.first);
            xs.push_back(pos.first + pos.second - 1);
        }
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        unordered_map<int, int> id;
        int n = xs.size();
        for(int i = 0; i < n; i++)
            id[xs[i]] = i;

        vector<int> ans;
        int max_h=  0;
        SegmentTree st(n);
        for(auto &pos: positions) {
            int b = pos.first, h = pos.second, e = b + h - 1;
            int new_h = st.query(id[b], id[e]) + h;
            st.update(id[b], id[e], new_h);
            max_h = max(max_h, new_h);
            ans.push_back(max_h);
        }
        return ans;
    }
};
