class MedianFinder {
    priority_queue<int> left;
    priority_queue<int ,vector<int>, std::greater<int>> right;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.empty()) {
            left.push(num);
        } else if(right.empty()) {
            if(num < left.top()) {
                right.push(left.top());
                left.pop();
                left.push(num);
            } else {
                right.push(num);
            }
        } else if(num > right.top()){
            if(right.size() > left.size()) {
                int tmp = right.top(); right.pop();
                left.push(tmp);
            }
            right.push(num);
        } else if(num < left.top()){
            if(left.size() > right.size()) {
                int tmp = left.top(); left.pop();
                right.push(tmp);
            }
            left.push(num);
        } else {
            if(left.size() <= right.size()) {
                left.push(num);
            } else {
                right.push(num);
            }
        }
    }
    
    double findMedian() {
        return left.size() == right.size() ? (left.top() + right.top()) * 1.0 / 2 : left.size() > right.size() ? left.top() : right.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
