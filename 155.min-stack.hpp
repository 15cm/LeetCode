class MinStack {
public:
    /** initialize your data structure here. */
    stack<pair<int, int>> s;
    MinStack() {
    }
    
    void push(int x) {
        int minVal = s.empty() ? x : min(s.top().second, x);
        s.push(make_pair(x, minVal));
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
