class Solution {
    struct Node {
        double val;
        Node *parent = this;
        Node() {}
        Node(double val): val(val) {}
    };
    unordered_map<string, Node*> uf;

    Node *find_parent(Node *x) {
        return x == x->parent ? x : x->parent = find_parent(x->parent);
    }
    void connect(Node *x, Node *y, double val) {
        Node *p = find_parent(x), *q = find_parent(y);
        if(p == q) return;
        double ratio = y->val * val / x->val;
        for(auto &pr: uf) {
            Node *node = pr.second;
            if(find_parent(node) == p) {
                node->val *= ratio;
            }
        }
        p->parent = q;
    }
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        int n = equations.size();
        for(int i = 0; i < n; i++) {
            string &s1 = equations[i].first, &s2 = equations[i].second;
            double val = values[i];
            if(!uf.count(s1) && !uf.count(s2)) {
                uf[s1] = new Node(val);
                uf[s2] = new Node(1);
                uf[s1]->parent = uf[s2];
            } else if(!uf.count(s1)) {
                uf[s1] = new Node(uf[s2]->val * val);
                uf[s1]->parent = uf[s2];
            } else if(!uf.count(s2)){
                uf[s2] = new Node(uf[s1]->val / val);
                uf[s2]->parent = uf[s1];
            } else {
                connect(uf[s1], uf[s2], val);
            }
        }
        vector<double> ans;
        for(auto &pr: queries) {
            string &s1 = pr.first, &s2 = pr.second;
            if(!(uf.count(s1) && uf.count(s2) && find_parent(uf[s1]) == find_parent(uf[s2]))) {
                ans.push_back(-1);
            } else {
                ans.push_back(uf[s1]->val / uf[s2]->val);
            }
        }
        return ans;
    }
};
