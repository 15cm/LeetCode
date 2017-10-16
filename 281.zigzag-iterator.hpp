typedef vector<int> VI;
typedef VI::iterator VIIT;
class ZigzagIterator {
public:
    int cur;
    vector<pair<VIIT, VIIT>> its;
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        cur = 0;
        if(!v1.empty()) {
            its.push_back(make_pair(v1.begin(), v1.end()));
        }
        if(!v2.empty()) {
            its.push_back(make_pair(v2.begin(), v2.end()));
        }
    }

    int next() {
        auto& pr = its[cur];
        int res = *pr.first;
        pr.first++;
        if(pr.first == pr.second) {
            vector<pair<VIIT, VIIT>> tmp;
            for(int i = cur + 1; i < its.size(); i++) {
                tmp.push_back(its[i]);
            }
            for(int i = 0; i < cur; i++) {
                tmp.push_back(its[i]);
            }
            cur = 0;
            its.swap(tmp);
        } else {
            cur = (cur + 1) % its.size();
        }
        return res;
    }

    bool hasNext() {
        return its.size() > 0;
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
