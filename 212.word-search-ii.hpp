class Trie {
    struct Node {
        bool isEnd;
        vector<Node*> next;
        Node(): isEnd(false), next(vector<Node*>(26, NULL)) {}
    };

    Node* root;

public:
    Trie(): root(NULL) {}

    void insert(string& s) {
        root = insert(root, 0, s);
    }
    Node* insert(Node* node, int p, string& s) {
        if(!node) node = new Node();
        if(p == s.length()) {
            node->isEnd = true;
            return node;
        }
        int idx = s[p] - 'a';
        node->next[idx] = insert(node->next[idx], p + 1, s);
        return node;
    }

    int find(string& s) {
        auto x = find(root, 0, s);
        int res = !x ? -1 : x->isEnd? 1 : 0;
        if(x) x->isEnd = false;
        return res;
    }
    Node* find(Node* node, int p, string& s) {
        if(!node) return NULL;
        if(p == s.length()) return node;
        int idx = s[p] - 'a';
        return find(node->next[idx], p + 1, s);
    }
};
class Solution {
    Trie trie;
    const int dx[4] = {0, 0, 1, -1};
    const int dy[4] = {1, -1, 0, 0};
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(board.empty() || board[0].empty()) return vector<string>();
        int m = board.size(), n = board[0].size();
        for(auto& s: words) {
            trie.insert(s);
        }

        string path;
        vector<string> ans;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                dfs(i, j, path, board, ans);
        return ans;
    }
    void dfs(int r, int c, string& path, vector<vector<char>>& board, vector<string>& ans) {
        int m = board.size(), n = board[0].size();
        char tmp = board[r][c];
        path.push_back(tmp);
        board[r][c] = '0';

        int found = trie.find(path);
        if(found != -1) {
            if(found == 1) {
                ans.push_back(path);
            }
            for(int i = 0; i < 4; i++) {
                int x = r + dx[i];
                int y = c + dy[i];
                if(x >= 0 && x < m && y >= 0 && y < n && board[x][y] != '0') {
                    dfs(x, y, path, board, ans);
                }
            }
        }
        path.pop_back();
        board[r][c] = tmp;
    }
};
