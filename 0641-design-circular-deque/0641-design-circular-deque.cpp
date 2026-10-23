class MyCircularDeque {
    vector<int> v;
    int front = 0;
    int back = 1;
    int size = 0;
public:
    MyCircularDeque(int k) {
        v.resize(k);
        front = v.size() - 1;
    }
    
    bool insertFront(int value) {
        if(isFull()) {
            return false;
        }
        int newFront = front - 1;
        newFront += v.size();
        newFront %= v.size();
        v[newFront] = value;
        size++;
        front = newFront;
        if(size == 1) {
            back = front;
        }
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) {
            return false;
        }
        int newBack = back + 1;
        newBack %= v.size();
        v[newBack] = value;
        back = newBack;
        size++;
        if(size==1){
            front=back;
        }
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) {
            return false;
        }
        front++;
        front %= v.size();
        size--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) {
            return false;
        }
        back--;
        back += v.size();
        back %= v.size();
        size--;
        return true;
    }
    
    int getFront() {
        if(isEmpty()) {
            return -1;
        }
        return v[front];
    }
    
    int getRear() {
        if(isEmpty()) {
            return -1;
        }
        return v[back];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == v.size();     
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */