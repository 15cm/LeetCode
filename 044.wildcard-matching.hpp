struct Edge {
private:
    int u, v;
public:
    Edge(int u, int v): u(u), v(v){}
    int from() { return u; }
    int to() { return v; }
};

class Digraph {
public:
    vector<vector<Edge>> adj;
    int V;
    Digraph(int V): V(V) {
        adj = decltype(adj)(V);
    }
    void addEdge(int from, int to) {
        adj[from].push_back(Edge(from, to));
    }
};

class DigraphDfs {
public:
    Digraph G;
    vector<bool> vis;
    DigraphDfs(Digraph G, int s): G(G) {
        vis = decltype(vis)(G.V);
        dfs(s);
    }
    DigraphDfs(Digraph G, list<int>& s): G(G) {
        vis = decltype(vis)(G.V);
        for(auto& u: s)
            if(!vis[u]) dfs(u);
    }
    void dfs(int u) {
        vis[u] = true;
        for(auto e: G.adj[u]) {
            int v = e.to();
            if(!vis[v]) dfs(v);
        }
    }
    bool marked(int u) { return vis[u]; }
};

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = p.length(), N = n + 2;
        Digraph G(N);
        // Build NFA
        G.addEdge(0, 1);
        for(int i = 0; i < n; i++) {
            int u = i + 1;
            if(p[i] == '*') {
                G.addEdge(u, u+1);
            }
        }
        // Match
        list<int> pc;
        DigraphDfs conn(G, 0);
        for(int i = 0; i < N; i++)
            if(conn.marked(i)) pc.push_back(i);
        for(auto&& c: s) {
            list<int> match;
            for(auto&& u: pc) {
                if(u < N - 1) {
                    if(c == p[u-1] || p[u-1] == '?')
                        match.push_back(u + 1);
                    else if(p[u-1] == '*')
                        match.push_back(u);
                }
            }

            pc.clear();
            DigraphDfs conn(G, match);
            for(int i = 0; i < N; i++)
                if(conn.marked(i)) pc.push_back(i);
        }

        for(auto& u: pc)
            if(u == N - 1) return true;
        return false;
    }
};
