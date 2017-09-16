class Solution {
    class Graph {
    public:
        vector<vector<int>> adj;
        int V;
        Graph(int V): V(V) {
            adj = decltype(adj)(V);
        }
        void addEdge(int from, int to) {
            adj[from].push_back(to);
        }
    };

    class GraphDfs {
        Graph G;
        vector<bool> vis;
    public:
        GraphDfs(Graph& G): G(G) {
            vis = decltype(vis)(G.V);
        }
        void search(int s) {
            fill(vis.begin(), vis.end(), false);
            dfs(s);
        }
        void search(list<int> s) {
            fill(vis.begin(), vis.end(), false);
            for(auto& u: s) {
                if(!vis[u]) dfs(u);
            }
        }
        void dfs(int u) {
            vis[u] = true;
            for(auto& v: G.adj[u])
                if(!vis[v]) dfs(v);
        }
        bool marked(int u) {
            return vis[u];
        }
    };
public:
    bool isMatch(string s, string p) {
        int n = p.length(), N = n + 2;
        Graph G(N);
        G.addEdge(0, 1);
        for(int i = 0; i < n; i++) {
            int index = i + 1;
            if(i < n - 1 && p[i + 1] == '*') {
                G.addEdge(index, index + 1);
                G.addEdge(index + 1, index);
            }
            if(p[i] == '*')
                G.addEdge(index, index + 1);
        }

        list<int> pc;
        GraphDfs dfs(G);
        dfs.search(0);
        for(int i = 0; i < N; i++)
            if(dfs.marked(i)) pc.push_back(i);
        for(auto& c: s) {
            list<int> match;
            for(auto& u: pc) {
                if(u < N - 1) {
                    char stat = p[u - 1];
                    if(stat == '.' || c == stat)
                        match.push_back(u + 1);
                }
            }

            pc.clear();
            dfs.search(match);
            for(int i = 0; i < N; i++)
                if(dfs.marked(i)) pc.push_back(i);
        }
        for(auto& u: pc) {
            if(u == N - 1) return true;
        }
        return false;
    }
};
