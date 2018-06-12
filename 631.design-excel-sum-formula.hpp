struct Cell {
    bool isDirty;
    int val;
    Cell() {
        isDirty = false;
        val = 0;
    }
};

struct pair_hash {
    size_t operator() (const pair<int, int> &pr) const {
        return ((size_t)pr.first << 32) | pr.second;
    }
};

class Excel {
public:
    vector<vector<Cell>> grid;
    vector<vector<vector<pair<int, int>>>> view2model;
    vector<vector<unordered_set<pair<int, int>, pair_hash>>> model2view;
    Excel(int H, char W) {
        int m = row(H) + 1, n = row(W) + 1;
        grid = decltype(grid)(m, decltype(grid)::value_type(n));
        model2view = decltype(model2view)(m, decltype(model2view)::value_type(n));
        view2model = decltype(view2model)(m, decltype(view2model)::value_type(n));
    }
    
    void set(int r, char c, int v) {
        set(row(r), col(c), v);
    }

    void set(int r, int c, int v) {
        auto &cell = grid[r][c];
        cell.isDirty = false;
        cell.val = v;
        view2model[r][c].clear();
        for(auto &vec: model2view)
            for(auto &deps: vec) {
                deps.erase({r, c});
            }
        for(auto &pr: model2view[r][c]) {
            touch(pr.first, pr.second);
        }
    }

    void touch(int r, int c) {
        auto &cell = grid[r][c];
        if(cell.isDirty) return;
        cell.isDirty = true;
        for(auto &pr: model2view[r][c]) {
            touch(pr.first, pr.second);
        }
    }
    
    int get(int r, char c) {
        return get(row(r), col(c));
    }

    int get(int r, int c) {
        auto &cell = grid[r][c];
        if(!cell.isDirty) return cell.val;
        int val = 0;
        for(auto &pr: view2model[r][c]) {
            int tr = pr.first, tc = pr.second;
            val += get(tr, tc);
        }
        cell.isDirty = false;
        return cell.val = val;
    }
    
    int sum(int r, char c, vector<string> strs) {
        return sum(row(r), col(c), strs);
    }

    int sum(int r, int c, const vector<string> &strs) {
        auto &cell = grid[r][c];
        set(r, c, 0);
        cell.isDirty = true;
        for(auto &s: strs) {
            int pos = s.find(':');
            if(pos == string::npos) {
                auto pr = parse(s);
                view2model[r][c].push_back(pr);
                model2view[pr.first][pr.second].emplace(r, c);
            } else {
                auto tl = parse(s.substr(0, pos));
                auto br = parse(s.substr(pos + 1));
                for(int i = tl.first; i <= br.first; i++)
                    for(int j = tl.second; j <= br.second; j++) {
                        view2model[r][c].emplace_back(i, j);
                        model2view[i][j].emplace(r, c);
                    }
            }
        }
        return get(r, c);
    }
    int row(int r) {
        return r - 1;
    }
    int col(char c) {
        return c - 'A';
    }
    pair<int, int> parse(const string& s) {
        return {row(stoi(s.substr(1))), col(s[0])};
    }
};

/**
 * Your Excel object will be instantiated and called as such:
 * Excel obj = new Excel(H, W);
 * obj.set(r,c,v);
 * int param_2 = obj.get(r,c);
 * int param_3 = obj.sum(r,c,strs);
 */
