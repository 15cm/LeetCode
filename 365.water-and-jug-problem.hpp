struct State {
    int a, b;
        
    State(int a, int b): a(a), b(b) {}

};

bool operator == (const State& lhs, const State& rhs) {
    return lhs.a == rhs.a && lhs.b == rhs.b;
}

struct statehash {
    size_t operator() (const State& s) const {
        return (((size_t) s.a) << 32) | s.b;
    }
};

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        unordered_set<State, statehash> memo;
        queue<State> q;
        q.push(State(0, 0));

        while(!q.empty()) {
            auto& s = q.front();
            q.pop();
            int a = s.a, b = s.b;
            int c;

            if(a == z || b == z || a + b == z) return true;
            if(memo.count(s)) continue;
            memo.insert(s);

            if(a != x) {
                q.push(State(x, b));
                c = min(x - a, b);
                q.push(State(a + c, b - c));
            }

            if(b != y) {
                q.push(State(a, y));
                c = min(a, y - b);
                q.push(State(a - c, b + c));
            }

            if(a != 0) {
                q.push(State(0, b));
            }

            if(b != 0) {
                q.push(State(a, 0));
            }
        }

        return false;
    }
};
