class MyCircularDeque {
private:
    int *a;
    int capacity;
    int head, rear;

    int prevPos(int p) {
        return (p - 1 + capacity) % capacity;
    }

    int nextPos(int p) {
        return (p + 1) % capacity;
    }

public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
      a = new int[k];
      capacity = k;
      head = rear = -1;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(isFull()) return false;
        if(isEmpty()) {
            head = rear = 0;
        }
        head = prevPos(head);
        a[head] = value;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(isFull()) return false;
        if(isEmpty()) {
            head = rear = 0;
        }
        a[rear] = value;
        rear = nextPos(rear);
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(isEmpty()) return false;
        head = nextPos(head);
        if(head == rear) {
            head = rear = -1;
        }
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(isEmpty()) return false;
        rear = prevPos(rear);
        if(head == rear) {
            head = rear = -1;
        }
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if(isEmpty()) return -1;
        return a[head];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if(isEmpty()) return -1;
        return a[prevPos(rear)];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return head == -1;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return !isEmpty() && head == rear;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque obj = new MyCircularDeque(k);
 * bool param_1 = obj.insertFront(value);
 * bool param_2 = obj.insertLast(value);
 * bool param_3 = obj.deleteFront();
 * bool param_4 = obj.deleteLast();
 * int param_5 = obj.getFront();
 * int param_6 = obj.getRear();
 * bool param_7 = obj.isEmpty();
 * bool param_8 = obj.isFull();
 */
