class MinStack {
private:
    struct elem{
        int val;
        int min;
    } ;
    std::stack<elem> stack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(stack.empty()){
            stack.push({val, val});
        } else {
            stack.push({val, min(val, stack.top().min)});
        }
    }
    
    void pop() {
        stack.pop();
    }
    
    int top() {
        return stack.top().val;
    }
    
    int getMin() {
        return stack.top().min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */