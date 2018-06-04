#define OPT_MKPARENT 1
#define OPT_TOUCH 2

struct Node {
    bool isDir;
    string name;
    string data;
    unordered_map<string, Node*> files;

    Node(const string &name): name(name) {}
    Node(bool isDir, const string &name): isDir(isDir), name(name) {}
    Node(bool isDir, const string &name, const string &data): isDir(isDir), name(name), data(data) {}
};

class FileSystem {
    Node *root;
public:
    FileSystem() {
        root = new Node(true, "/");
    }
    
    vector<string> ls(string path) {
        auto names = splitPath(path);
        vector<string> res;
        auto x = findPath(names);
        if(!x) return {};
        if(x->isDir) {
            if(x->files.size()) {
                for(auto &pr: x->files) {
                    res.push_back(pr.first);
                }
            }
        } else {
            res.emplace_back(x->name);
        }
        sort(res.begin(), res.end());
        return res;
    }
    
    void mkdir(string path) {
        auto names = splitPath(path);
        if(names.empty()) return;
        auto dir = names.back();
        names.pop_back();
        auto x = findPath(names, OPT_MKPARENT);
        x->files[dir] = new Node(true, dir);
    }
    
    void addContentToFile(string filePath, string content) {
        auto names = splitPath(filePath);
        auto x = findPath(names, OPT_TOUCH);
        if(!x || x->isDir) return;
        x->data += content;
    }
    
    string readContentFromFile(string filePath) {
        auto names = splitPath(filePath);
        auto x = findPath(names);
        if(!x || x->isDir) return "";
        return x->data;
    }

    vector<string> splitPath(string path) {
        stringstream ss(path);
        vector<string> res;
        string s;
        getline(ss, s, '/');
        while(getline(ss, s, '/')) {
            res.emplace_back(s);
        }
        return res;
    }

    Node* findPath(const vector<string> &names, int optHandleNotExist = 0) {
        if(names.empty()) return root;
        auto x = root;
        for(auto &name: names) {
            if(!x->files.count(name)) {
                switch(optHandleNotExist) {
                case OPT_MKPARENT:
                    x->files[name] = new Node(true, name);
                    break;
                case OPT_TOUCH:
                    x->files[name] = new Node(false, name);
                    break;
                default:
                    return NULL;
                }
            }
            x = x->files[name];
        }
        return x;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem obj = new FileSystem();
 * vector<string> param_1 = obj.ls(path);
 * obj.mkdir(path);
 * obj.addContentToFile(filePath,content);
 * string param_4 = obj.readContentFromFile(filePath);
 */
