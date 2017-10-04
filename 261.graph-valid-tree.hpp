class Solution {
    vector<int> id;
    int cnt;
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        id = vector<int>(n);
        cnt = n;
        for(int i = 0; i < n; i++)
            id[i] = i;
        for(auto& e: edges) {
            int u = e.first, v = e.second;
            if(!isConnected(u, v)) {
                connect(u, v);
            } else {
                return false;
            }
        }
        return cnt == 1;
    }
    int find(int p) {
        return p == id[p] ? p : (id[p] = find(id[p]));
    }
    bool isConnected(int p, int q) {
        return find(p) == find(q);
    }
    void connect(int p, int q) {
        int pid = find(p);
        int qid = find(q);
        if(pid != qid) {
            id[pid] = qid;
            cnt--;
        }
    }
};
