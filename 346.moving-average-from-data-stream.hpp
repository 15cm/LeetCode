class MovingAverage {
public:
    /** Initialize your data structure here. */
    int capacity, sum;
    deque<int> dq;
    MovingAverage(int size) {
        capacity = size;
        sum = 0;
    }
    
    double next(int val) {
        double res;
        dq.push_back(val);
        sum += val;
        if(dq.size() <= capacity) {
            res = sum * 1.0 / dq.size();
        } else {
            sum -= dq.front();
            dq.pop_front();
            res = sum * 1.0 / capacity;
        }
        return res;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
